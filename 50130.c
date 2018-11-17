#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define MAXN 32

char name[MAXN][200];
int money[MAXN];

// -1: unregistered
int get_username_index(char *username){
    for(int i=0; i<MAXN; i++){
        if(strcmp(username, name[i]) == 0) return i;
    }
    return -1;
}

// -1: invalid
int get_mode(char *mode){
    if(strstr(mode, "earns") != NULL) return 1;
    if(strstr(mode, "spends") != NULL) return 2;
    if(strstr(mode, "gives") != NULL) return 3;
    if(strstr(mode, "becomes") != NULL) return 4;
    return -1;
}

/* After decrypting, the command should be a
   trimmed command if it is valid.
-1: invalid
 1: earns
 2: spends
 3: gives
 4: becomes                               */
int decrypt(char *command, int *user1_idx, int *user2_idx, int *amount){
    char *user, *mode, *amount_str;
    int to_return;

    user = strtok(command, " ");
    *user1_idx = get_username_index(user);
    if(*user1_idx == -1) return -1;

    mode = strtok(NULL, " ");
    to_return = get_mode(mode);
    if(to_return == -1) return -1;

    if(to_return == 3){
        user = strtok(NULL, " ");
        *user2_idx = get_username_index(user);
        if(*user2_idx == -1) return -1;
    }

    amount_str = strtok(NULL, " ");
    sscanf(amount_str, "%d", amount);

    return to_return;
}

int main(){
    int N;
    scanf("%d", &N);

    char command[200];
    // initialize
    for(int i=0; i<N; i++){
        scanf("%s %d", name[i], &money[i]);
    }

    // operation
    while(fgets(command, 200, stdin) != NULL){
        int user1_idx, user2_idx, amount;
        switch(decrypt(command, &user1_idx, &user2_idx, &amount)){
            case 1:
                money[user1_idx] += amount;
                break;
            case 2:
                if(money[user1_idx] >= amount) money[user1_idx] -= amount;
                break;
            case 3:
                if(money[user1_idx] >= amount){
                    money[user1_idx] -= amount;
                    money[user2_idx] += amount;
                }
                break;
            case 4:
                money[user1_idx] = amount;
                break;
        }
    }

    for(int i=0; i<N; i++){
        printf("%s %d\n", name[i], money[i]);
    }


#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
