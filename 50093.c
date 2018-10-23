#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0


int main(){
    char S[10000];
    scanf("%s", S);

    char cmd[1100];
    
    while(scanf("%s", cmd) != EOF){
        if(cmd[0] == 'p'){
            printf("%s\n", S);
            continue;
        }

        char delimiter = cmd[1];
        char A[510], B[510], tmpS[10000];
        // extract A and B
        int index=2, insert=0;
        while(cmd[index] != delimiter){
            A[insert++] = cmd[index++];
        } A[insert] = '\0';

        insert=0; index++;
        while(cmd[index] != delimiter){
            B[insert++] = cmd[index++];
        } B[insert] = '\0';

        char *ptr_start = strstr(S, A);
        if(ptr_start == NULL) continue;
        char *ptr=S, *ins=tmpS;
        while(ptr != ptr_start){
            *ins = *ptr;
            ins++; ptr++;
        }
        strcpy(ins, B);
        ins += strlen(B);
        ptr += strlen(A);
        while(*ptr != '\0'){
            *ins = *ptr;
            ins++; ptr++;
        }
        *ins = '\0';

        strcpy(S, tmpS);
        
    }
    
        
#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

