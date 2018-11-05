#include <stdio.h>

#define bool int
#define true 1
#define false 0

#define MAXN 16384

typedef long long int lli;
lli weight[MAXN];

// find balance point of [start , end)
void find_bp(int start, int end){
    if(end-start < 3) return;

    for(int i=start; i<end; i++){
        // test if this index is balance point
        lli left=0, right=0;
        for(int j=start; j<i; j++) left += weight[j]*(i-j);
        for(int j=i+1; j<end; j++) right += weight[j]*(j-i);
        if(left==right){
            find_bp(start, i);
            printf("%d\n", i);
            find_bp(i+1, end);
            break;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &weight[i]);

    find_bp(0, n);

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
