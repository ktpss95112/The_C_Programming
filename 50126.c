#include <stdio.h>
 
void merge(int A[], int B[], int* a[], int* b[]){
    // get size of A adn B
    int size_a=1, size_b=1;
    for(int cnt=0; a[cnt]!=NULL; cnt++, size_a++);
    for(int cnt=0; b[cnt]!=NULL; cnt++, size_b++);
 
    int i=0, j=0;
    int **current_insert;
    if(A[i] < B[j]){
        current_insert = &a[0];
        i++;
    }
    else{
        current_insert = &b[0];
        j++;
    }
 
    while(i<size_a && j<size_b){
        if(A[i] < B[j]){
            *current_insert = &A[i];
            current_insert = &a[i];
            i++;
            continue;
        }
        else{
            *current_insert = &B[j];
            current_insert = &b[j];
            j++;
            continue;
        }
    }
 
    /*if  i == size of A:
        for j to size of B:
            complete remaining numbers in B.
    else if  j == size of B:
        for i to size of A:
            complete remaining numbers in A.*/
    if(i == size_a){
        *current_insert = &B[j];
        while(j != size_b-1){
            b[j] = &B[j+1];
            j++;
        }
        b[j] = NULL;
    }
    else{
        *current_insert = &A[i];
        while(i != size_a-1){
            a[i] = &A[i+1];
            i++;
        }
        a[i] = NULL;
    }
}
