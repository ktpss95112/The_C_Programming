// memory.h starts here
// the first piece of memory is always {0, 0}
// the last piece of memory is always {MAXLEN, 0}
typedef struct node{
    int start, length;
    struct node *prev, *next;
} Memory;
void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);
// memory.h ends here

// upload starts here
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "memory.h"
void initMemory(Memory *memory, int length){
    Memory *second = (Memory*)malloc(sizeof(Memory));
    Memory *end = (Memory*)malloc(sizeof(Memory));
    memory->start = 0;
    memory->length = 0;
    memory->prev = NULL;
    memory->next = second;
    second->start = 0;
    second->length = length;
    second->prev = memory;
    second->next = end;
    end->start = length;
    end->length = 0;
    end->prev = second;
    end->next = NULL;
}
int isHead(Memory *memory){
    return ((memory->start==0) && (memory->length==0));
}
int isEnd(Memory *memory){
    return (memory->next == NULL);
}
void printMemory(Memory *memory){
    if(isEnd(memory)) return;
    if(isHead(memory)){
        printf("==========\n");
        printMemory(memory->next);
        return;
    }
    if(memory->length != 0) printf("start %d, length %d\n", memory->start, memory->length);
    printMemory(memory->next);
}
void allocateMemory(Memory *memory, int start, int length){
    assert(memory != NULL);
    if(memory->length == 0){
        allocateMemory(memory->next, start, length);
        return;
    }
    int m_start=memory->start, m_end=memory->start+memory->length;
    //if(m_end-1 < start){
    if(start >= m_end){
        allocateMemory(memory->next, start, length);
        return;
    }

    Memory *prev = memory->prev;
    Memory *next = memory->next;
    // case 0: |       to_allocate       |
    if(start==m_start && start+length==m_end){
        prev->next = next;
        next->prev = prev;
        free(memory);
        return;
    }

    // case 1: |to_allocate |   remain   |
    else if(start == m_start){
        memory->start = m_start + length;
        memory->length -= length;
        return;
    }

    // case 2: |   memory   | to_allocate|
    else if(start+length == m_end){
        memory->length -= length;
        return;
    }

    // case 3: |memory|to_allocate|remain|
    else{
        Memory *remain = (Memory*)malloc(sizeof(Memory));
        memory->next = remain;
        remain->prev = memory;
        remain->next = next;
        next->prev = remain;
        memory->length = start - m_start;
        remain->start = start + length;
        remain->length = m_end - remain->start;
        return;
    }
}
void concat(Memory *memory){
    Memory *prev = memory->prev;
    Memory *next = memory->next;
    if(isEnd(next)) return;
    if(isHead(memory)){
        concat(next);
        return;
    }
    int m_end=memory->start+memory->length;
    if(m_end == next->start){
        prev->next = next;
        next->prev = prev;
        next->start = memory->start;
        next->length += memory->length;
        free(memory);
    }
    concat(next);
}
void freeMemory(Memory *memory, int start, int length){
    int m_end=memory->start+memory->length;
    Memory *next = memory->next;
    // |memory|to_free|next|
    if((start >= m_end) && (start+length <= next->start)){
        Memory *to_free = (Memory*)malloc(sizeof(Memory));
        to_free->start = start;
        to_free->length = length;
        to_free->prev = memory;
        to_free->next = next;
        memory->next = to_free;
        next->prev = to_free;
        concat(memory);
        return;
    }
    freeMemory(next, start, length);
    return;
}
// upload ends here
