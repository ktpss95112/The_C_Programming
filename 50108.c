// construct.c starts here
#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

#ifndef MAXLENGTH
#define MAXLENGTH 5
#endif

typedef struct Heap{ int value, index; } Heap; // increasing
int compar(void const *a, void const *b){
    if(((Heap*)a)->value < ((Heap*)b)->value) return -1;
    if(((Heap*)a)->value > ((Heap*)b)->value) return 1;
    return 0;
}
void insert(Heap B[], int value, int index){
    for(int i=MAXLENGTH-1; i>=0; i--){
        if(value > B[i].value){
            int tmpval=value, tmpidx=index;
            value=B[i].value; index=B[i].index;
            B[i].value=tmpval; B[i].index=tmpidx;
        }
    }
}
int index_of_kth(int sequence[], int l, int r){
    Heap B[16384];
    int i=l;
    for(int cnt=0; cnt<MAXLENGTH; i++, cnt++){
        B[cnt].value = sequence[i];
        B[cnt].index = i;
    }
    qsort(B, MAXLENGTH, sizeof(Heap), compar);
    for( ; i<r; i++) insert(B, sequence[i], i);
    return B[0].index;
}
Node* no_kth(int sequence[], int l, int r){
    if(l == r) return NULL;
    Node *current = (Node*)malloc(sizeof(Node));
    current->value = sequence[r-1];
    current->left = no_kth(sequence, l, r-1);
    current->right = NULL;
    return current;
}
Node* construct(int sequence[], int l, int r){
    if(r-l < MAXLENGTH) return no_kth(sequence, l, r);

    Node *current = (Node*)malloc(sizeof(Node));
    int index = index_of_kth(sequence, l, r);
    current->value = sequence[index];
    current->left = construct(sequence, l, index);
    current->right = construct(sequence, index+1, r);
    return current;
}
Node* ConstructTree(int sequence[], int N){
    return construct(sequence, 0, N);
}
// construct.c ends here
