// upload starts here
#include <stdlib.h>
void printbits(unsigned long long int n){
    int toprint[64];
    for(int i=0; i<64; i++){
        toprint[63-i] = abs(n%2);
        n >>= 1;
    }
    for(int i=0; i<64; i++) printf("%d", toprint[i]);
    printf("\n");
}

int get_ithbit(unsigned long long int n, int i){
    // MSB: 0, LSB: 63
    return (n>>(63-i))%2;
}
void ins_ithbit(unsigned long long int *n, int i, int value){
    // MSB: 0, LSB: 63
    // suppose that the bit in n is 0;
    *n += ((unsigned long long int)value<<(63-i));
}

unsigned long long int tmp[1048576];
void transmission(long long int belt[],int N,int T){
    //printf("N %d T %d\n", N, T);
    // shift
    for(int i=0; i<N; i++){
        for(int b=0; b<64; b++){
            int src_num = i*64+b;
            int dst_num = (src_num-T+N*64)%(N*64);
            int desti_idx = dst_num/64;
            int desti_bit = dst_num%64;
            //printf("%d %d\n", desti_idx, desti_bit);
            ins_ithbit(&(tmp[desti_idx]), desti_bit, get_ithbit(belt[i], b));
        }
    }
    //for(int i=0; i<N; i++) printbits(tmp[i]);
    // copy back to belt
    for(int i=0; i<N; i++) belt[i] = tmp[i];
}
// upload ends here
