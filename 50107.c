#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define MAXN 100001
#define MAXLEN 65

typedef struct{
    int weight, height;
    float bmi;
    char name[MAXLEN];
} Student;
Student stu[MAXN];

int compar(void const *a, void const *b){
    Student *aa = (Student*)a;
    Student *bb = (Student*)b;
    if(aa->bmi < bb->bmi) return -1;
    if(aa->bmi > bb->bmi) return 1;
    if(aa->weight < bb->weight) return -1;
    if(aa->weight > bb->weight) return 1;
    if(aa->height < bb->height) return -1;
    if(aa->height > bb->height) return 1;
    return strcmp(aa->name, bb->name);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s%d%d", stu[i].name, &stu[i].height, &stu[i].weight);
        stu[i].bmi = (float)stu[i].weight / (stu[i].height/100.0) / (stu[i].height/100.0);
    }

    qsort(stu, n, sizeof(Student), compar);

    for(int i=0; i<n; i++){
        printf("%s %d %d\n", stu[i].name, stu[i].height, stu[i].weight);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
