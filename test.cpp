#include <iostream>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a+b);
    
#ifdef DEBUG
    while(1);
#endif
    return 0;
}
