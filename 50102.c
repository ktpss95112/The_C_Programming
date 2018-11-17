#include <stdio.h>
#include <assert.h>
 
#define bool int
#define true 1
#define false 0
 
int get_size(FILE *f){
    fseek(f, 0, SEEK_END);
    return ftell(f);
}
 
// for debug usage
void dump_file(char name[35]){
    FILE *ftemp = fopen(name, "rb");
    printf("filename: %s\n", name);
    int c;
    while((c = fgetc(ftemp)) != EOF){
        printf("%02x", c);
    }
    printf("\n");
    fclose(ftemp);
}
 
int main(){
    char in1[35], in2[35], out[35];
    scanf("%s%s%s", in1, in2, out);
 
    FILE *fin1 = fopen(in1, "rb");
    FILE *fin2 = fopen(in2, "rb");
    FILE *fout = fopen(out, "wb");
    assert(fin1!=NULL && fin2!=NULL && fout!=NULL);
 
    int size1=get_size(fin1), size2=get_size(fin2);
 
    // make fin1 be the largest number
    if(size2 > size1){
        FILE *tmp = fin1;
        fin1 = fin2;
        fin2 = tmp;
        int tmpi = size1;
        size1 = size2;
        size2 = tmpi;
    }
 
    fseek(fin1, -1, SEEK_END);
    fseek(fin2, -1, SEEK_END);
    fseek(fout, size1-1, SEEK_SET);
 
    // add mutual bytes
    int carry = 0;
    while(1){
        int a=0, b=0, ans=0;
        fread(&a, 1, 1, fin1);
        fread(&b, 1, 1, fin2);
        ans = a+b+carry;
        if(ans >= (1<<8)) carry = 1;
        else              carry = 0;
        fwrite(&ans, 1, 1, fout);
        if(ftell(fin2) == 1) break;
        fseek(fin1, -2, SEEK_CUR);
        fseek(fin2, -2, SEEK_CUR);
        fseek(fout, -2, SEEK_CUR);
    }
    fclose(fin2);
 
    // paste remain bytes
    if(ftell(fin1) != 1){
        fseek(fin1, -2, SEEK_CUR);
        fseek(fout, -2, SEEK_CUR);
        while(1){
            int a=0, ans=0;
            fread(&a, 1, 1, fin1);
            ans = a+carry;
            if(ans >= (1<<8)) carry = 1;
            else              carry = 0;
            fwrite(&ans, 1, 1, fout);
            if(ftell(fin1) == 1) break;
            fseek(fin1, -2, SEEK_CUR);
            fseek(fout, -2, SEEK_CUR);
        }
    }
    fclose(fin1);
    fclose(fout);
 
#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
