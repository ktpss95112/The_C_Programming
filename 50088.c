
void travel(int map[1024][1024], int N, int M, int A_r,\
    int A_c, int B_r, int B_c, int directionA[], int directionB[]){
    //N=y , M=x
    char mark[1024][1024]={0};
    int ax=A_c, ay=A_r, bx=B_c, by=B_r;
    int dx[8]={1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8]={0, 0, 1, -1, 1, -1, -1, 1};
    int insert_a=0, insert_b=0;
    int stop_a=0, stop_b=0;

    mark[ay][ax] = 1;
    mark[by][bx] = 1;
    while(1){
        if(stop_a && stop_b) break;

        //a
        int max_direction_a, min_direction_b;
        if(!stop_a){
            int max_height=map[ay][ax], old_height=map[ay][ax];
            for(int i=0; i<8; i++){
                if(ay+dy[i]<0 || ay+dy[i]>=N) continue;
                if(ax+dx[i]<0 || ax+dx[i]>=M) continue;

                if(map[ay+dy[i]][ax+dx[i]] > max_height){
                    max_height = map[ay+dy[i]][ax+dx[i]];
                    max_direction_a = i;
                }
            }
            //They cannot find a uphill/downhill neighbor.
            if(max_height == old_height){
                stop_a = 1;
                directionA[insert_a++] = -1;
            }
        }

        //b
        if(!stop_b){
            int min_height=map[by][bx], old_height=map[by][bx];
            for(int i=0; i<8; i++){
                if(by+dy[i]<0 || by+dy[i]>=N) continue;
                if(bx+dx[i]<0 || bx+dx[i]>=M) continue;
                
                if(map[by+dy[i]][bx+dx[i]] < min_height){
                    min_height = map[by+dy[i]][bx+dx[i]];
                    min_direction_b = i;
                }
            }
            //They cannot find a uphill/downhill neighbor.
            if(min_height == old_height){
                stop_b = 1;
                directionB[insert_b++] = -1;
            }
        }


        if(!stop_a){
            ax += dx[max_direction_a];
            ay += dy[max_direction_a];
            directionA[insert_a++] = max_direction_a;
        }
        if(!stop_b){
            bx += dx[min_direction_b];
            by += dy[min_direction_b];
            directionB[insert_b++] = min_direction_b;
        }

        //They go into the same cell.
        if(ay==by && ax==bx){
            directionA[insert_a++] = -1;
            directionB[insert_b++] = -1;
            stop_a = 1;
            stop_b = 1;
        }

        //They go into cell that has been visited by the other traveler.
        if(mark[ay][ax] == 1){
            directionA[insert_a++] = -1;
            stop_a = 1;
        }
        else mark[ay][ax] = 1;
        if(mark[by][bx] == 1){
            directionB[insert_b++] = -1;
            stop_b = 1;
        }
        else mark[by][bx] = 1;
    }
}
