#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main(){

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
