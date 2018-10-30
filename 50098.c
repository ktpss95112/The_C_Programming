#include <stdio.h>

// debug
#include <stdlib.h>
void printbits(unsigned long long int n){
    int toprint[64];
    for(int i=0; i<64; i++){
        toprint[63-i] = abs(n%2);
        n >>= 1;
    }
    for(int i=0; i<64; i++) printf("%d", toprint[i]);
    printf("\n");
}

#define bool int
#define true 1
#define false 0

#define MAXN 100
#define MAXK 100
#define MAXM 64

#define CANNOT -1
#define PRINTED -2

typedef unsigned long long int LLU;
LLU club[MAXN];

int N, K;

// suppose club_to_test valid, club_remain >= 1
int stack[MAXK];
int recur(LLU people_now, int club_to_test, int club_remain){
    if((club[club_to_test] & people_now) != 0) return CANNOT;
    stack[K-club_remain] = club_to_test;

    if(club_remain == 1){
        for(int i=0; i<K; i++) printf("%d\n", stack[i]);
        return PRINTED;
    }

    int next_club_to_test = club_to_test + 1;
    while(next_club_to_test+club_remain <= N+1){
        int catch = recur((people_now | club[club_to_test]), next_club_to_test, club_remain-1);
        if(catch == CANNOT) next_club_to_test++;
        if(catch == PRINTED) return PRINTED;
    }
    return CANNOT;
}

int main(){
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++){
        int M;
        scanf("%d", &M);
        for(int j=0; j<M; j++){
            int bit;
            scanf("%d", &bit);
            club[i] += ((LLU)1 << bit);
        }
    }
    // debug
    /*for(int i=0; i<N; i++){
        printbits(club[i]);
    }*/

    for(int i=0; i<N; i++){
        int catch = recur(0, i, K);
        if(catch == PRINTED) break;
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
