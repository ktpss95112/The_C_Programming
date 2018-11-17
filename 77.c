// upload starts here
#include <stdio.h>
#include "node.h"
unsigned int getSize(struct node *head, unsigned int depth){
    if(head->next == NULL) return depth+1;
    return getSize(head->next, depth+1);
}
struct node *getNode(struct node *head, unsigned int i){
    unsigned int size = getSize(head, 0);
    if(i >= size) return NULL;
    i = size-i-1;
    struct node *to_return = head;
    for(int j=0; j<i; j++) to_return = to_return->next;
    return to_return;
}
// upload ends here
