#include <stdio.h>
int **first[110], *second[110][3000];
int ***constructTable(int A[], int B[]){
    int *b_pointer = &B[0];
    int a;
    for(a=0; A[a]!=0; a++){
        first[a] = &second[a][0];
        for(int i=0; i<A[a]; i++){
            second[a][i] = b_pointer;
            while(*b_pointer != 0) b_pointer++;
            b_pointer++;
        }
        second[a][A[a]] = NULL;
    }
    first[a] = NULL;
    return &first[0];
}
