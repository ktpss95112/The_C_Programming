#include <stdio.h>

#define bool int
#define true 1
#define false 0

#define MAXN 24

void construct(int N, int M, unsigned char valid_code[]);
void print_valid(unsigned char code, int N, unsigned char valid_code[]);
unsigned long long int reverse_bits(unsigned long long int llu);
int h_distance(unsigned char code, unsigned char valid_code);

#ifdef DEBUG
unsigned char reverse_bits_uc(unsigned char uc){
    unsigned char ans=0;
    for(int i=0; i<8; i++, uc/=2) ans = ans*2 + uc%2;
    return ans;
}
void print_binary(unsigned char uc){
    uc = reverse_bits_uc(uc);
    for(int i=0; i<8; i++){
        printf("%d", uc%2);
        uc /= 2;
    }
    printf("\n");
}
#endif

int main(){
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);

    unsigned char valid_code[MAXN];
    construct(N, M, valid_code);

    /*for(int i=0; i<N; i++){
        print_binary(valid_code[i]);
        printf("%d\n", valid_code[i]);
    }*/

    while(P--){
        unsigned char input;
        scanf("%hhu", &input);
        print_valid(input, N, valid_code);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

void construct(int N, int M, unsigned char valid_code[]){
    unsigned long long int llu;
    for(int insert=0; insert<N; insert++){
        if(insert%8 == 0){
            scanf("%llu", &llu);
            llu = reverse_bits(llu);
        }
        for(int cnt=0; cnt<8; cnt++){
            valid_code[insert] = valid_code[insert]*2 + llu%2;
            llu /= 2;
        }
    }
}

void print_valid(unsigned char code, int N, unsigned char valid_code[]){
    for(int i=0; i<N; i++){
        if(h_distance(code, valid_code[i]) <= 1) printf("%hhu\n", valid_code[i]);
    }
}

unsigned long long int reverse_bits(unsigned long long int llu){
    unsigned long long int ans=0;
    for(int i=0; i<64; i++, llu/=2) ans = ans*2 + llu%2;
    return ans;
}

int h_distance(unsigned char code, unsigned char valid_code){
    int cnt=0;
    for(int i=0; i<8; i++){
        if(code%2 != valid_code%2) cnt++;
        code /= 2;
        valid_code /= 2;
    }
    return cnt;
}
