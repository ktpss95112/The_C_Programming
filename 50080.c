#include <stdio.h>
 
int main(){
    int N;
    int bflag = 0;
    while(scanf("%d", &N) != EOF){
        int max = -100000, min = 100000;
        int tmp;
        for(int i = 0; i < N; i++){
            if(scanf("%d", &tmp) != EOF){
                max = (tmp>max) ? tmp : max;
                min = (tmp<min) ? tmp : min;
            }
            else{
                printf("%d\n", min);
                bflag = 1;
                break;
            }
        }
        if(bflag) break;

        printf("%d\n", max);
    }

#ifdef DEBUG
    while(1);
#endif
  return 0;
}
