#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    char name[15][70];
    int board[15][256][256];
    for(int i=0; i<n; i++){
        scanf("%s", name[i]);
        for(int j=0; j<m; j++)
            for(int k=0; k<m; k++)
                scanf("%d", &board[i][j][k]);
    }

    short pos_x[15][256*256], pos_y[15][256*256];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                pos_x[i][board[i][j][k]] = k;
                pos_y[i][board[i][j][k]] = j;
            }
        }
    }

    int in, cnt=0;
    int someone_wins = false;
    int cnt_ver[15][256]={0}, cnt_hor[15][256]={0}, cnt_dia[15][2]={0};
    while(scanf("%d", &in) != EOF){
        cnt++;
        //printf("%d\n", in);
        if(someone_wins) continue;

        for(int i=0; i<n; i++){
            //mark in
            int x=pos_x[i][in], y=pos_y[i][in];

            cnt_ver[i][x]++;
            cnt_hor[i][y]++;
            if(x==y) cnt_dia[i][0]++;
            if(x+y==m-1) cnt_dia[i][1]++;

            if(cnt < m) continue;
            //check if wins
            if(cnt_ver[i][x]==m || cnt_hor[i][y]==m\
            || cnt_dia[i][0]==m || cnt_dia[i][1]==m){
                if(someone_wins) printf(" %s", name[i]);
                else printf("%d %s", in, name[i]);
                someone_wins = true;
            }
            
        }
    }
    printf("\n");


#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
