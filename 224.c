// upload starts here
#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init_storage(Employee **storage, int n){
    // allocate memory space to store employee data
    // no need to understand this function now.
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
void free_storage(Employee **storage){
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id(Employee *set, int n, int id){
    for(int i=0; i<n; i++)
        if(set[i].id == id) return set+i;
}
Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name){
    for(int i=0; i<n; i++)
        if(strcmp(set[i].first_name, first_name)==0
            && strcmp(set[i].last_name, last_name)==0) return set+i;
}
Employee* find_root_boss(Employee *set, int n, Employee *employee){
    int current_id = employee->id;
    Employee *current_em = employee;
    while(current_id != current_em->boss_id){
        current_id = current_em->boss_id;
        current_em = find_employee_by_id(set, n, current_id);
    }
    return current_em;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *root_of_A = find_root_boss(set, n, A);
    Employee *root_of_B = find_root_boss(set, n, B);

    /// case default: no relation
    if(root_of_A != root_of_B) return -1;

    int current_id = A->id;
    Employee *current_em = A;
    while(current_id != current_em->boss_id){ // while not root
        // case 1: subordinate
        if(current_id == B->id) return 1;

        current_id = current_em->boss_id;
        current_em = find_employee_by_id(set, n, current_id);
    }
    if(current_id == B->id) return 1;

    current_id = B->id;
    current_em = B;
    while(current_id != current_em->boss_id){ // while not root
        // case 2: supervisor
        if(current_id == A->id) return 2;

        current_id = current_em->boss_id;
        current_em = find_employee_by_id(set, n, current_id);
    }
    if(current_id == A->id) return 2;

    // case 3: colleage
    return 3;
}
// upload ends here
