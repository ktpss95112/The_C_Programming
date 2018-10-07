#include <stdio.h>
 
int main(){
    int N, M, R;
    scanf("%d%d%d", &N, &M, &R);
    int q;
    while(scanf("%d", &q) != EOF){
        if(R == 0){
            if(N >= q)      N -= q;
            else if(M >= q) M -= q;
        }
        else{
            if(N <= M){
                if(N >= q)      N -= q;
                else if(M >= q) M -= q;
            }
            else{
                if(M >= q)      M -= q;
                else if(N >= q) N -= q;
            }
        }
        printf("%d %d\n", N, M);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
