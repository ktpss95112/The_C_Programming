#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool ainb(char a, char *b){
    for(int i=0; i<strlen(b); i++){
        if(b[i] == a) return true;
    }
    return false;
}


int main(){
    int T;
    scanf("%d", &T);

    short table[26][26] = {0};
    char train[110];
    while(scanf("%s", train) != EOF){
        for(int i=0; i<strlen(train)-1; i++){
            int now_char=train[i]-'a', next_char=train[i+1]-'a';
            table[now_char][next_char] ++;
        }
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            printf("%d", table[i][j]);
            if(j != 25) printf(" ");
        }
        printf("\n");
    }

    // find first
    int max_times = 0;
    int now_char, next_char;
    char printed[30] = "";
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(table[i][j]>max_times && table[i][j]>T){
                max_times = table[i][j];
                now_char = i;
                next_char = j;
            }
        }
    }

    // exception handle
    if(max_times == 0){
        printf("\n");
        return 0;
    }

    // print first
    printf("%c%c", now_char+'a', next_char+'a');
    printed[0] = now_char+'a';
    printed[1] = next_char+'a';
    printed[2] = '\0';

    // process
    for(int insert=2; ; insert++){
        max_times = 0;
        now_char = next_char;

        for(int i=0; i<26; i++){
            if(table[now_char][i]>max_times
            && table[now_char][i]>T
            && !ainb(i+'a', printed)){
                max_times = table[now_char][i];
                next_char = i;
            }
        }

        // exception handle
        if(max_times == 0){
            printf("\n");
            break;
        }

        printf("%c", next_char+'a');
        printed[insert] = next_char+'a';
        printed[insert+1] = '\0';
    }
        
#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

