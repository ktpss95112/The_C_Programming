#include <stdio.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

int get_size(FILE *f){
    int current_position = ftell(f);
    fseek(f, 0, SEEK_END);
    int ans = ftell(f);
    fseek(f, current_position, SEEK_SET);
    return ans;
}

unsigned char reverse_bits(unsigned char data){
    unsigned char ans=0;
    for(int i=0; i<8; i++){
        int current_bit = (data & (1<<i)) ? 1 : 0;
        ans += (current_bit << (7-i));
    }
    return ans;
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
    char inname[20], outname[20];
    scanf("%s%s", inname, outname);
    FILE *fin = fopen(inname, "rb");
    FILE *fout = fopen(outname, "wb");
    assert(fin!=NULL && fout!=NULL);

    int N;
    scanf("%d", &N);
    int size = get_size(fin);
    for(int src_idx=0; src_idx<size; src_idx++){
        int des_idx;
        unsigned char data;
        des_idx = (size-src_idx-1-N + 3*size) % size;
        fread(&data, 1, 1, fin);
        data = reverse_bits(data);
        fseek(fout, des_idx, SEEK_SET);
        fwrite(&data, 1, 1, fout);
    }

    fclose(fin);
    fclose(fout);

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
