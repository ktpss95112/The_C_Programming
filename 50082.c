#include <stdio.h>
 
int main(){
    int ar=0, br=0; //r: ready
    int arrive, a, b;
    while(scanf("%d%d%d", &arrive, &a, &b) != EOF){
        if(ar <= arrive) ar = arrive+a;
        else             ar = ar+a;

        if(br <= ar) br = ar+b;
        else         br = br+b;

        printf("%d\n", br);
    }
    

#ifdef DEBUG
    while(1);
#endif
  return 0;
}
