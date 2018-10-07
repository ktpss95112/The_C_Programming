#include <stdio.h>

#define bool int
#define true 1
#define false 0

const int dx[6] = {0, 1, 0, -1, 0, 1};
const int dy[6] = {0, 0, 1, 0, -1, 1};
 
int main(){
    int N, M, L, W; //N: y, M: x, L:y, W:x
    scanf("%d%d%d%d", &N, &M, &L, &W);
    int map[500][500]={0};
    for(int i=0; i<L; i++)
        for(int j=0; j<W; j++) map[i][j] = 1;
    int O;
    scanf("%d", &O);
    while(O--){
        int x, y;
        scanf("%d%d", &x, &y);
        map[y][x] = 2;
    }
    
    int command, current_x=0, current_y=0;
    while(scanf("%d", &command) != EOF){
        if(command == 0){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++) printf("%d", map[i][j]);
                printf("\n");
            }
#ifdef DEBUG
            printf("\n");
#endif
            continue;
        }

        int new_current_x=current_x + dx[command];
        int new_current_y=current_y + dy[command];

        //out of range
        if(new_current_x+W>M || new_current_x<0 || new_current_y+L>N || new_current_y<0){
#ifdef DEBUG
            printf("OOF\n");
#endif
            continue;
        }

        //more than one obstacle
        int cnt = 0;
        switch(command){
            case 1:
                for(int i=new_current_y; i<new_current_y+L; i++)
                    if(map[i][new_current_x+W-1] == 2) cnt++;
                break;
            case 2:
                for(int j=new_current_x; j<new_current_x+W; j++)
                    if(map[new_current_y+L-1][j] == 2) cnt++;
                break;
            case 3:
                for(int i=new_current_y; i<new_current_y+L; i++)
                    if(map[i][new_current_x] == 2) cnt++;
                break;
            case 4:
                for(int j=new_current_x; j<new_current_x+W; j++)
                    if(map[new_current_y][j] == 2) cnt++;
                break;
            case 5:
                for(int i=new_current_y; i<new_current_y+L-1; i++)
                    if(map[i][new_current_x+W-1] == 2) cnt++;
                for(int j=new_current_x; j<new_current_x+W; j++)
                    if(map[new_current_y+L-1][j] == 2) cnt++;
                break;
        }
#ifdef DEBUG
        printf("cnt %d\n", cnt);
#endif
        if(cnt > 1) continue;

        //update
        //int up_right = map[current_y][current_x+W];
        //int down_left = map[current_y+L][current_x];
        switch(command){
            case 1:
                for(int i=new_current_y; i<new_current_y+L; i++){
                    map[i][new_current_x+W-1] = 1;
                    map[i][current_x] = 0;
                }
                break;
            case 2:
                for(int j=new_current_x; j<new_current_x+W; j++){
                    map[new_current_y+L-1][j] = 1;
                    map[current_y][j] = 0;
                }
                break;
            case 3:
                for(int i=new_current_y; i<new_current_y+L; i++){
                    map[i][new_current_x] = 1;
                    map[i][current_x+W-1] = 0;
                }
                break;
            case 4:
                for(int j=new_current_x; j<new_current_x+W; j++){
                    map[new_current_y][j] = 1;
                    map[current_y+L-1][j] = 0;
                }
                break;
            case 5:
                for(int i=current_y; i<current_y+L; i++)
                    map[i][current_x] = 0;
                for(int i=new_current_y; i<new_current_y+L; i++)
                    map[i][new_current_x+W-1] = 1;
                for(int j=current_x; j<current_x+W; j++)
                    map[current_y][j] = 0;
                for(int j=new_current_x; j<new_current_x+W; j++)
                    map[new_current_y+L-1][j] = 1;
                break;
        }


        current_x = new_current_x;
        current_y = new_current_y;
        
#ifdef DEBUG
        printf("cx %d | cy %d\n", current_x, current_y);
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) printf("%d", map[i][j]);
            printf("\n");
        }
        printf("\n");
#endif
    }
    

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}


/* TLE version
#include <stdio.h>

#define bool int
#define true 1
#define false 0

 
int main(){
    int N, M, L, W; //N: y, M: x, L:y, W:x
    scanf("%d%d%d%d", &N, &M, &L, &W);
    int map[500][500]={0};
    for(int i=0; i<L; i++)
        for(int j=0; j<W; j++) map[i][j] = 1;
    int O;
    scanf("%d", &O);
    while(O--){
        int x, y;
        scanf("%d%d", &x, &y);
        map[y][x] = 2;
    }
    
    int command, current_x=0, current_y=0;
    while(scanf("%d", &command) != EOF){
        if(command == 0){
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++) printf("%d", map[i][j]);
                printf("\n");
            }
#ifdef DEBUG
            printf("\n");
#endif
            continue;
        }

        int new_current_x=current_x, new_current_y=current_y;
        switch(command){
            case 1:
                new_current_x ++;
                break;
            case 2:
                new_current_y ++;
                break;
            case 3:
                new_current_x --;
                break;
            case 4:
                new_current_y --;
                break;
            case 5:
                new_current_x ++;
                new_current_y ++;
                break;
        }

        //out of range
        if(new_current_x+W>M || new_current_x<0 || new_current_y+L>N || new_current_y<0){
#ifdef DEBUG
            printf("OOF\n");
#endif
            continue;
        }
        //more than one obstacle
        int cnt = 0;
        for(int i=new_current_y; i<new_current_y+L; i++)
            for(int j=new_current_x; j<new_current_x+W; j++)
                if(map[i][j] == 2) cnt++;
        if(cnt > 1) continue;

        //update
        for(int i=current_y; i<current_y+L; i++)
            for(int j=current_x; j<current_x+W; j++)
                map[i][j] = 0;
        for(int i=new_current_y; i<new_current_y+L; i++)
            for(int j=new_current_x; j<new_current_x+W; j++)
                map[i][j] = 1;

        current_x = new_current_x;
        current_y = new_current_y;
        
#ifdef DEBUG
        printf("cx %d | cy %d\n", current_x, current_y);
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) printf("%d", map[i][j]);
            printf("\n");
        }
        printf("\n");
#endif
    }
    

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
*/
