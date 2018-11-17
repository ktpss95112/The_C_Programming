#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MAXNUM 2147483647

typedef struct{
    int n, friends[10];
} Friends;

int N, M;
Friends person[11];
int min_ans = MAXNUM; // update when line is full
int line[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int current_pos[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
void recur(int current_num, int prev_ans){
    if(current_num == N){
        if(prev_ans < min_ans) min_ans = prev_ans;
        return;
    }
    for(int i=0; i<N; ++i){
        if(line[i] == -1){
            line[i] = current_num;
            current_pos[current_num] = i;
            // calculate current ans
            int current_ans = prev_ans;
            for(int j=0; j<person[current_num].n; ++j){
                int f = person[current_num].friends[j];
                if(f > current_num) break;
                current_ans += (abs(current_pos[f]-i));
            }

            // cut
            if(current_ans >= min_ans){
                line[i] = -1;
                current_pos[current_num] = -1;
                continue;
            }
            recur(current_num+1, current_ans);
            line[i] = -1;
            current_pos[current_num] = -1;
        }
    }
}

int compar(void const *a, void const *b){
    int aa = *((int*)a);
    int bb = *((int*)b);
    if(aa<bb) return -1;
    if(aa>bb) return 1;
    return 0;
}

int main(){
    int M;
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        person[a].friends[person[a].n++] = b;
        person[b].friends[person[b].n++] = a;
    }

    for(int i=0; i<N; i++) qsort(person[i].friends, person[i].n, sizeof(int), compar);

    recur(0, 0);
    printf("%d\n", min_ans);

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
