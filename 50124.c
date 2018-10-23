// main.c
#include <stdio.h>
#define MAXN 100
#define MAXM 100*100
 
int validMoveNum(int r, int c, int n, int visited[100][100]);
int nextMove(int r, int c, int n, int visited[100][100]);
 
void printAns(int n, int visited[100][100], int stepCount[100][100]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d", 10000*visited[i][j] + stepCount[i][j]);
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }
}
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
 
    int r[MAXM], c[MAXM];
    int visited[MAXN][MAXN]={0};
    int stepCount[MAXN][MAXN]={0};
 
    int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};
 
    for(int i=0; i<m; i++){
        scanf("%d%d", &r[i], &c[i]);
        visited[r[i]][c[i]] = i+1;
    }
 
    int step = 1;
    while(1){
        int someOneMove = 0;
        for(int i=0; i<m; i++){
            visited[r[i]][c[i]] = 0;
            int nxtm = nextMove(r[i], c[i], n, visited);
            visited[r[i]][c[i]] = i+1;
            if(nxtm == -1) continue;
 
            r[i] += dy[nxtm];
            c[i] += dx[nxtm];
            visited[r[i]][c[i]] = i+1;
            stepCount[r[i]][c[i]] = step;
            someOneMove = 1;
        }
        if(!someOneMove) break;
        step++;
    }
 
    printAns(n, visited, stepCount);
 
#ifdef DEBUG
    while(1);
#endif
    return 0;
}



// validMoveNum.c
// r:y, c:x
int validMoveNum(int r, int c, int n, int visited[100][100]){
    //printf("r %d c %d\n", r, c);
    if(r<0 || r>=n || c<0 || c>=n) return -1;
    if(visited[r][c]) return -1;
 
    int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};
    int count=0;
 
    for(int d=0; d<8; d++){
        // out of range
        if(r+dy[d]<0 || r+dy[d]>=n) continue;
        if(c+dx[d]<0 || c+dx[d]>=n) continue;
 
        if(!visited[r+dy[d]][c+dx[d]]) count++;
    }
    return count;
}



// nextMove.c
int validMoveNum(int r, int c, int n, int visited[100][100]);
 
int nextMove(int r, int c, int n, int visited[100][100]){
    int has_valid_move=0;
 
    int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};
 
    int min_d, min_p=100;
    for(int d=0; d<8; d++){
        int tmp=validMoveNum(r+dy[d], c+dx[d], n, visited);
        if(tmp == -1) continue;
 
        if(tmp<min_p){
            min_p = tmp;
            min_d = d;
            has_valid_move = 1;
        }
    }
 
    if(!has_valid_move) return -1;
    return min_d;
}
