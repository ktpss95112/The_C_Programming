#include <stdio.h>
#include <assert.h>

#define offset 32768

int main(){
    char filename[210];
    scanf("%s", filename);
    FILE *fin = fopen(filename, "rb");
    assert(fin != NULL);

    int n;
    fread(&n, 4, 1, fin);

    int count[32768+offset] = {0};
    for (int i=0; i<n; ++i){
        short temp;
        fread(&temp, 2, 1, fin);
        count[temp+offset] ++;
    }

    int max_idx, max_cnt=0;
    for(int i=-32768; i<32768; i++){
        if(count[i+offset] >= max_cnt){
            max_cnt = count[i+offset];
            max_idx = i;
        }
    }

    printf("%d\n%d\n", max_idx, max_cnt);

    fclose(fin);

    return 0;
}
