#include <stdio.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

int main(){
    char in1[35], in2[35], out[35];
    scanf("%s%s%s", in1, in2, out);

    FILE *fin1 = fopen(in1, "rb");
    FILE *fin2 = fopen(in2, "rb");
    FILE *fout = fopen(out, "wb");
    assert(fin1!=NULL && fin2!=NULL && fout!=NULL);

    

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
