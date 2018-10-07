#include <stdio.h>

#define bool int
#define true 1
#define false 0

int max(int a, int b){
    if(a>b) return a;
    return b;
}
 
int main(){
    int N, M;
    int taskCompTime[500]={0}, mach[500][500]={0}, cost[500][500]={0};
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++){
        int q;
        scanf("%d%d", &taskCompTime[i], &q);
        for(int j=0; j<q; j++) scanf("%d%d", &mach[i][j], &cost[i][j]);
    }

    int nextTask[500]={0}, machCompTime[500]={0};
    while(1){
        //condition
        bool breakFlag = true;
        for(int i=0; i<M; i++) if(cost[i][nextTask[i]] != 0) breakFlag = false;
        if(breakFlag) break;

        int job, minCompTime=1000000;
        for(int i=0; i<M; i++){
            if(cost[i][nextTask[i]] == 0) continue;
            int tmp = max(taskCompTime[i], machCompTime[mach[i][nextTask[i]]])
                    + cost[i][nextTask[i]];
            if(tmp < minCompTime){
                job = i;
                minCompTime = tmp;
            }
        }

        machCompTime[mach[job][nextTask[job]]] = minCompTime;
        taskCompTime[job] = minCompTime;
        nextTask[job]++;
    }

    for(int i=0; i<M; i++) printf("%d\n", taskCompTime[i]);

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
