#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define MAXLEN 16
#define MAXPAPER 20000

typedef struct pair{
    char name[MAXLEN];
    int num;
} Pair;

int compar(void const *a, void const *b){
    Pair *aa=(Pair*)a, *bb=(Pair*)b;
    int tmp = strcmp(aa->name, bb->name);
    if(tmp != 0) return tmp;
    if(aa->num > bb->num) return -1;
    if(aa->num < bb->num) return 1;
    return 0;
}

int main(){
    int N=0;
    Pair p[MAXPAPER];
    for( ; scanf("%s%d", p[N].name, &p[N].num)!=EOF; N++);
    qsort(p, N, sizeof(Pair), compar);

    char current_name[MAXLEN];
    strcpy(current_name, p[0].name);
    int start=0;
    for(int i=0; i<N+1; i++){
        if(i==N || strcmp(current_name, p[i].name)!=0){
            // process
            int count=1;
            for(int j=start; j<i && p[j].num>=count; j++, count++);
            printf("%s %d\n", current_name, count-1);
            strcpy(current_name, p[i].name);
            start = i;
        }
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
