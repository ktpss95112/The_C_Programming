#include <stdio.h>

#define bool int
#define true 1
#define false 0

int days[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,\
                   0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

 
int main(){
    int year, init;
    scanf("%d%d", &year, &init);

    bool leap;
    if     (year%4   != 0) leap = false;
    else if(year%100 != 0) leap = true;
    else if(year%400 != 0) leap = false;
    else                   leap = true;

    int n;
    scanf("%d", &n);
    while(n--){
        int mon, dat;
        scanf("%d%d", &mon, &dat);

        if(mon>12 || mon<1){
            printf("-1\n");
            continue;
        }
        if(dat>days[leap][mon] || dat<1){
            printf("-2\n");
            continue;
        }

        int cnt=init;
        for(int i=1; i<mon; i++) cnt+=days[leap][i];
        cnt += (dat-1);

        printf("%d\n", cnt%7);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
  return 0;
}
