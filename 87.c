// upload starts here
#include <stdio.h>
#include "node.h"
void merge2(struct node *list1, struct node *list2, struct node *prev){
    if(list1 == NULL){
        prev->next = list2;
        return;
    }
    if(list2 == NULL){
        prev->next = list1;
        return;
    }
    //printf("l1 %d l2 %d pr %p\n", list1->value, list2->value, prev);
    if(list1->value < list2->value){
        prev->next = list1;
        merge2(list1->next, list2, prev->next);
        return;
    }
    else{
        prev->next = list2;
        merge2(list1, list2->next, prev->next);
        return;
    }
}
struct node *merge(struct node *list1, struct node *list2){
    struct node root;
    merge2(list1, list2, &root);
    return root.next;
}
// upload ends here
