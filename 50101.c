#include"componentPart.h"
#include <stdlib.h>
#include <string.h>
int compar(const void *a, const void *b){
    return strcmp(((ComponentPart*)a)->name, ((ComponentPart*)b)->name);
}

int findPriceRecursive(int index, ComponentPart list[]){
    if(list[index].price != 0) return list[index].price;
    int ans = 0;
    for(int i=0; i<list[index].numComponent; i++){
        ans += findPriceRecursive(list[index].componentPartList[i], list);
    }
    list[index].price = ans;
    return ans;
}

void findPrice(int N, ComponentPart list[]){
    for (int i=0; i<N; ++i){
        if(list[i].numComponent!=0 && list[i].price==0) findPriceRecursive(i, list);
    }
    qsort(list, N, sizeof(ComponentPart), compar);
    for (int i = 0; i < N; ++i){
        printf("%s %d\n", list[i].name, list[i].price);
    }
}
