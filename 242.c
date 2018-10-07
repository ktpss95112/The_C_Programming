#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

 
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int cx[3], cy[3], r[3];
        for(int i=0; i<3; i++) scanf("%d%d%d", &cx[i], &cy[i], &r[i]);

        int cnt=0;
        int done[3]={0};
        //case n: c[n]'s rectangle no intersection with others'
        for(int i=0; i<3; i++){
            int i1=(i+1)%3, i2=(i+2)%3;
            int dx1=cx[i]-cx[i1], dy1=cy[i]-cy[i1];
            int dx2=cx[i]-cx[i2], dy2=cy[i]-cy[i2];

            int no_intersection = false;
            if( (abs(dx1)>800 || abs(dy1)>800)
             && (abs(dx2)>800 || abs(dy2)>800)) no_intersection = 1;
            else if( (dx1*dx1+dy1*dy1)>800 && (dx2*dx2+dy2*dy2)>800 ) no_intersection = 1;
            
            if(no_intersection){
                for(int j=cy[i]-r[i]; j<=cy[i]+r[i]; j++){
                    for(int k=cx[i]-r[i]; k<=cx[i]+r[i]; k++){
                        int dx=cx[i]-k, dy=cy[i]-j;
                        if(dx*dx+dy*dy <= r[i]*r[i]) cnt++;
                    }
                }
                done[i] = 1;
            }
        }
        if(done[0]+done[1]+done[2] == 3){
            printf("%d\n", cnt);
            continue;
        }
        //deal with intersections
        int left=2147483647, right=-2147483648, up=-2147483648, down=2147483647;
        for(int i=0; i<3; i++){
            if(done[i]) continue;
            if(cx[i]-r[i] < left)  left = cx[i]-r[i];
            if(cx[i]+r[i] > right) right = cx[i]+r[i];
            if(cy[i]-r[i] < down)  down = cy[i]-r[i];
            if(cy[i]+r[i] > up)    up = cy[i]+r[i];
        }
        for(int y=down; y<=up; y++){
            for(int x=left; x<=right; x++){
                //
                int tmp=0; // represents how many circles contain (x, y)
                for(int i=0; i<3; i++){
                    if(done[i]) continue;
                    int dx=cx[i]-x, dy=cy[i]-y;
                    if(dx*dx+dy*dy <= r[i]*r[i]) tmp++;
                }

                if(tmp==1 || tmp==3) cnt++;
            }
        }
        printf("%d\n", cnt);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
