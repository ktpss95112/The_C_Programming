#include <stdio.h>
 
int main(){
    int xmax, ymax, x=0, y=0, q;
    scanf("%d%d", &xmax, &ymax);
    printf("0\n0\n");
    while(scanf("%d", &q) != EOF){
        switch(q%5){
            case 1:
                if(x+q < xmax){
                    x += q;
                    printf("%d\n%d\n", x, y);
                }
                break;
            case 2:
                if(x-q >= 0){
                    x -= q;
                    printf("%d\n%d\n", x, y);
                }
                break;
            case 3:
                if(y+q < ymax){
                    y += q;
                    printf("%d\n%d\n", x, y);
                }
                break;
            case 4:
                if(y-q >= 0){
                    y -= q;
                    printf("%d\n%d\n", x, y);
                }
                break;
        }
    }

#ifdef DEBUG
    while(1);
#endif
  return 0;
}
