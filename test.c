#include <stdio.h>

#define bool int
#define true 1
#define false 0

void chasing(int **A[], int a, int *B[], int b, int C[], int c);

int main(){
    char str[100];
    while(fgets(str, 99, stdin) != NULL){
        char fromc, toc, remain[100];
        int fromi, toi;
        int cnt = sscanf(str, "%c %d %c %d %s", &fromc, &fromi, &toc, &toi, remain);
        printf("%d\n", cnt);
    }



    int a = 5, b = 4, c = 3;
    int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
    chasing(A, a, B, b, C, c);

    int **ansA[5] = {} ,*ansB[4] = {};
    for (int i = 0; i < a; i++)
        ansA[i] = NULL;
    for (int i = 0; i < b; i++)
        ansB[i] = NULL;
    ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
    /*Check A*/
    for (int i = 0; i < a; i++)
        if (A[i] != ansA[i] )
            printf("A[%d] wrong answer!\n", i);

    /*Check B*/
    for (int i = 0; i < b; i++)
        if (B[i] != ansB[i] )
            printf("B[%d] wrong answer!\n", i);
        

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    char cmd[70];
    while(fgets(cmd, 64, stdin) != NULL){
        char fromc, toc, remain[100];
        int fromi, toi;
        if(sscanf(cmd, "%c %d %c %d", &fromc, &fromi, &toc, &toi, remain) != 4) continue;

    }

}
