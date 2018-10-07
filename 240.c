#include <stdio.h> 

#define bool int
#define true 1
#define false 0

int main(){
    int n; scanf("%d", &n);
    while(n--){
        int x[4], y[4];
        for(int i=0; i<4; i++) scanf("%d%d", &x[i], &y[i]);

        //sort
        int cross_of_0102 = (((x[1]-x[0]) * (y[2]-y[0])
                            - (x[2]-x[0]) * (y[1]-y[0])) > 0)? 1:-1;
        int cross_of_0103 = (((x[1]-x[0]) * (y[3]-y[0])
                            - (x[3]-x[0]) * (y[1]-y[0])) > 0)? 1:-1;
        int cross_of_0203 = (((x[2]-x[0]) * (y[3]-y[0])
                            - (x[3]-x[0]) * (y[2]-y[0])) > 0)? 1:-1;
        if(cross_of_0102*cross_of_0103 < 0){
            //swap(1, 2)
            int tmpx = x[1], tmpy = y[1];
            x[1] = x[2]; y[1] = y[2];
            x[2] = tmpx; y[2] = tmpy;
        }
        else if(cross_of_0102*cross_of_0203 < 0){
                //swap(2, 3)
                int tmpx = x[2], tmpy = y[2];
                x[2] = x[3]; y[2] = y[3];
                x[3] = tmpx; y[3] = tmpy;
        }

        int dx01=x[1]-x[0], dy01=y[1]-y[0];
        int dx02=x[2]-x[0], dy02=y[2]-y[0];
        int dx03=x[3]-x[0], dy03=y[3]-y[0];
        int dx12=x[2]-x[1], dy12=y[2]-y[1];
        int dx13=x[3]-x[1], dy13=y[3]-y[1];
        int dx23=x[3]-x[2], dy23=y[3]-y[2];
        int d01=dx01*dx01+dy01*dy01;
        int d02=dx02*dx02+dy02*dy02;
        int d03=dx03*dx03+dy03*dy03;
        int d12=dx12*dx12+dy12*dy12;
        int d13=dx13*dx13+dy13*dy13;
        int d23=dx23*dx23+dy23*dy23;
        bool edge=false, point=false;

        if(d01==d12 && d12==d23 && d23==d03) edge = true;
        if(d01+d12==d02 && d12+d23==d13 && d23+d03==d02) point = true;

        if( edge &&  point) printf("square\n");
        if( edge && !point) printf("diamond\n");
        if(!edge &&  point) printf("rectangle\n");
        if(!edge && !point) printf("other\n");

    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
