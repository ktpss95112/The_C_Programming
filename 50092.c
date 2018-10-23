#include <stdio.h>

#define bool int
#define true 1
#define false 0

void chasing(int **A[], int a, int *B[], int b, int C[], int c);

int main(){
    
    int a = 3, b = 3, c = 3;
        int **A[3] = {}, *B[3] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[3] = {} ,*ansB[3] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[0] = &B[0], ansA[1] = &B[2], ansB[0] = &C[2], ansB[1] = &C[1];
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

#include <stdio.h>
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    for(int i=0; i<a; i++) A[i] = B[i] = NULL;

    char cmd[70];
    while(fgets(cmd, 64, stdin) != NULL){
        //printf("DEBUG %s", cmd);
        char froms[100], tos[100], remain[100];
        char fromc, toc;
        int fromi, toi;
        if(sscanf(cmd, "%s%d%s%d%s", froms, &fromi, tos, &toi, remain) != 4){
            printf("0\n");
            continue;
        }
        if(!(froms[1]=='\0' && tos[1]=='\0')){
            printf("0\n");
            continue;
        }
        fromc = froms[0];
        toc = tos[0];
        //printf("  DEBUG %c %d %c %d\n", fromc, fromi, toc, toi);

        int to_print = 0;
        if(fromc=='A' && fromi<a && fromi>=0){
            if(toc=='B' && toi<b && toi>=0) A[fromi] = &B[toi], to_print = 1;//, printf("_AB_\n");
        }
        if(fromc=='B' && fromi<b && fromi>=0){
            if(toc=='C' && toi<c && toi>=0) B[fromi] = &C[toi], to_print = 1;//, printf("_BC_\n");
        }
        if(to_print == 1) printf("1\n");
        else              printf("0\n");
    }

}
