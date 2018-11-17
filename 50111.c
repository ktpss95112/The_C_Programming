#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MAXN 1010
#define MAXE 150000

typedef struct node{
    int n, neis[MAXN];
} City;
City c[MAXN];

int compar(void const *a, void const *b){
    if(*(int*)a < *(int*)b) return -1;
    if(*(int*)a > *(int*)b) return 1;
    return 0;
}
void sort_neis(int N){
    for(int i=0; i<N; i++) qsort(c[i].neis, c[i].n, sizeof(int), compar);
}

bool find_path(int i, int N, bool visited[], int buffer[], int buffer_ins, int first){
    if(buffer_ins==N && i==first){
        buffer[buffer_ins] = i;
        return true;
    }
    if(visited[i] == true) return false;
    visited[i] = true;
    for(int index=0; index<c[i].n; index++){
        if(find_path(c[i].neis[index], N, visited, buffer, buffer_ins+1, first)){
            buffer[buffer_ins] = i;
            return true;
        }
    }
    visited[i] = false;
    return false;
}

int main(){
    int N, E;
    scanf("%d%d", &N, &E);

    // init
    for(int i=0; i<N; i++) c[i].n = 0;

    for(int i=0; i<E; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        c[a].neis[c[a].n++] = b;
        c[b].neis[c[b].n++] = a;
    }

    sort_neis(N);

    bool visited[MAXN] = {false};
    int buffer[MAXN];
    for(int i=0; i<N; i++){
        if(find_path(i, N, visited, buffer, 0, i)){
            for(int j=0; j<=N; j++) printf("%d%c", buffer[j], ((j==N)?'\n':' '));
            return 0;
        }
        visited[i] = false;
    }
    printf("NO SOLUTION\n");

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
