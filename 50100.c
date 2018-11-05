#include "compute.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[64];
    int citation_count;
    int papers_count;
} RESULT;
RESULT result[1024];
int num_count = 0;
int index_of_result(char *str){
    for(int i=0; i<num_count; i++){
        if(strcmp(str, result[i].name) == 0) return i;
    }
    return -1;
}
/*
void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));
*/
int compar(const void *a, const void *b){
    return strcmp(((RESULT*)a)->name, ((RESULT*)b)->name);
}

void compute(paper P[], int N){
    // construct name table
    for(int i=0; i<N; i++){
        if(index_of_result(P[i].journalName) == -1){
            strcpy(result[num_count].name, P[i].journalName);
            result[num_count].citation_count = 0;
            result[num_count].papers_count = 0;
            num_count ++;
        }
    }

    // count numerator, denominator
    // numerator  : citations
    // denominator: papers
    for(int i=0; i<N; i++){
        int index = index_of_result(P[i].journalName);
        result[index].papers_count ++;
        for(int j=0; j<P[i].numCitedPaper; j++){
            int cited_paper = P[i].citedPaperIndex[j];
            index = index_of_result(P[cited_paper].journalName);
            result[index].citation_count ++;
        }
    }

    // sort
    qsort(result, num_count, sizeof(RESULT), compar);

    // print the result
    for(int i=0; i<num_count; i++){
        printf("%s %d/%d\n", result[i].name
                           , result[i].citation_count
                           , result[i].papers_count);
    }
}
