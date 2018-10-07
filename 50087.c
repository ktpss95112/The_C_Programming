#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main(){
    int n;
    scanf("%d", &n);
    int w[2048];
    for(int i=0; i<n; i++) scanf("%d", &w[i]);

    int v, swap=0;
    bool balanced = false;
    while(!balanced){
        for(v=1; v<n-1; v++){
            int left=0, right=0;
            for(int i=0; i<v; i++) left += (v-i)*w[i];
            for(int i=v+1; i<n; i++) right += (i-v)*w[i];

            if(left == right){
                //printf("v %d\nleft %d right %d\n", v, left, right);
                balanced = true;
                break;
            }
        }
        if(balanced) break;

        int tmp = w[swap];
        w[swap] = w[n-1-swap];
        w[n-1-swap] = tmp;
        swap ++;
    }

    for(int i=0; i<n; i++){
        if(i == v) printf("v");
        else       printf("%d", w[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
