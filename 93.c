// upload start here
#include <stdio.h>
#include "heap.h"

void initialize(struct Heap *heap){
    heap->num = 0;
}
int removeMin(struct Heap *heap){
    int pos, min=2147483647;
    for(int i=0; i<heap->num; i++){
        if(heap->ary[i] < min){
            min = heap->ary[i];
            pos = i;
        }
    }
    heap->ary[pos] = heap->ary[heap->num-1];
    heap->num --;
    return min;
}
void add(struct Heap *heap, int i){
    heap->ary[heap->num] = i;
    heap->num ++;
}
int isFull(struct Heap *heap){
    if(heap->num == MAXHEAP) return 1;
    return 0;
}
int isEmpty(struct Heap *heap){
    if(heap->num == 0) return 1;
    return 0;
}
// upload ends here
