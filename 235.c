// not finish yet
// https://judgegirl.csie.org/problem/0/235

#include <stdio.h>

#define bool int
#define true 1
#define false 0

typedef struct{
    int nume; // numerator
    int deno; // denominator
} Fraction;

int gcd(int a, int b);
void simplify(Fraction *a);
void add(Fraction a, Fraction b, Fraction *destination);
void mul(Fraction a, Fraction b, Fraction *destination);
Fraction newFrac(int nume, int deno);

int main(){
    int n;
    scanf("%d", &n);

    // init
    Fraction arr[2][20];
    arr[0][0] = newFrac(0, 1);
    arr[1][0] = newFrac(1, 1);
    for(int i=1; i<20; i++){
        arr[0][i] = newFrac(0, 1);
        arr[1][i] = newFrac(0, 1);
    }

    // start
    for(int layer=0; layer<n; layer++){
        for(int j=0; j<=layer; j++){
            int l, r;
            scanf("%d%d", &l, &r);
            Fraction tmp, toAdd;
            tmp.deno = l+r;
            // left
            tmp.nume = l;
            mul(tmp, arr[(layer+1)%2][j], &toAdd);
            add(arr[layer%2][j]);
            // right
            tmp.nume = r; mul(tmp, arr[(layer+1)%2][j], arr[layer%2][j+1]);
        }
    }

#ifdef TEST
    Fraction test, tmp;
    test.nume = 6;
    test.deno = 2;
    tmp.nume = 4;
    tmp.deno = 3;
    add(test, tmp, &test);
    printf("%d %d\n", test.nume, test.deno);
#endif

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

Fraction newFrac(int nume, int deno){
    Fraction tmp;
    tmp.nume = nume;
    tmp.deno = deno;
    return tmp;
}

int gcd(int a, int b){
    if(b) while((a%=b) && (b%=a));
    return a+b;
}

void simplify(Fraction *a){
    int tmp = gcd(a->nume, a->deno);
    a->nume /= tmp;
    a->deno /= tmp;
}

void add(Fraction a, Fraction b, Fraction *destination){
    destination->deno = a.deno * b.deno;
    destination->nume = a.nume*b.deno + b.nume*a.deno;
    simplify(destination);
}

void mul(Fraction a, Fraction b, Fraction *destination){
    destination->deno = a.deno * b.deno;
    destination->nume = a.nume * b.nume;
    simplify(destination);
}

