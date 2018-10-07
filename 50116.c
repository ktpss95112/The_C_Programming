#include <stdio.h>

#define bool int
#define true 1
#define false 0

 
int main(){
    int cnt=0, buffer=0, input, cntz=0, last;
    while(scanf("%d", &input) != EOF){
        last = input;
        if(input==0) cntz++;
        if(cnt%2) buffer += input;
        else      buffer -= input;
        cnt++;
    }
    int eleven;
    if(buffer%11 == 0) eleven=1;
    else               eleven=0;
    printf("%d\n%d\n%d\n%d\n", cnt, (last%2==0), cntz, eleven);

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
