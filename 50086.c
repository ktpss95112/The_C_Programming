#include <stdio.h>

#define bool int
#define true 1
#define false 0

#define MAXN 32768+10
#define MAXK 256+10

int friends[MAXN][MAXK], insert[MAXN]={0};

int main(){
    int N, E;
    scanf("%d%d", &N, &E);
    for(int i=0; i<N; i++)
        for(int j=0; j<MAXK; j++)
            friends[i][j] = -1;
    while(E--){
        int a, b;
        scanf("%d%d", &a, &b);
        friends[a][insert[a]++] = b;
        friends[b][insert[b]++] = a;
    }

#ifdef DEBUG
    for(int i=0; i<6; i++){
        for(int j=0; friends[i][j]!=-1; j++){
            printf("%d ", friends[i][j]);
        }
        printf("\n");
    }
#endif

    bool invited[MAXN]={0};
    int tmp;
    while(scanf("%d", &tmp) != EOF){
        invited[tmp] = true;
        for(int i=0; friends[tmp][i]!=-1; i++) invited[friends[tmp][i]] = true;
    }
    for(int i=0; i<N; i++){
        if(!invited[i]) printf("%d\n", i);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
