#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define MAXN 1024
#define MAXLI 1024
#define MAXL 16384
#define MAXSMW 1024
#define MAXBGW 10000000

char allwords[MAXBGW] = {0};
char *word[MAXL];
char **line[MAXN];

void construct();
char* insert(char *str);
void swap(int l1, int w1, int l2, int w2);
void output();

int main(){
    construct();
    int M;
    scanf("%d", &M);
    while(M--){
        int l1, w1, l2, w2;
        scanf("%d%d%d%d", &l1, &w1, &l2, &w2);
        swap(l1, w1, l2, w2);
    }
    output();

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

void construct(){
    int N;
    scanf("%d", &N);
    getchar();
    char tmp_line[MAXLI*MAXSMW];
    int ins_word = 0;
    for(int i=0; i<N; i++){
        fgets(tmp_line, MAXLI*MAXSMW, stdin);
        line[i] = &word[ins_word];

        char *delim = " \n";
        char *tmp_word = strtok(tmp_line, delim);
        while(tmp_word != NULL){
            word[ins_word++] = insert(tmp_word);
            tmp_word = strtok(NULL, delim);
        }
    }
}

int ins_allwords = 0;
char* insert(char *str){
    int i=0;
    char *to_be_return = allwords + ins_allwords;
    while(str[i] != '\0') allwords[ins_allwords++] = str[i++];
    allwords[ins_allwords++] = '\0';
    return to_be_return;
}

void swap(int l1, int w1, int l2, int w2){
    char *tmp = *(line[l1]+w1);
    *(line[l1]+w1) = *(line[l2]+w2);
    *(line[l2]+w2) = tmp;
}

void output(){
    for(int idx_line=0; line[idx_line]!=NULL; idx_line++){
        char **ptr_word=line[idx_line];
        while((ptr_word+1!=line[idx_line+1]) && (*(ptr_word+1)!=NULL)){
            printf("%s ", *ptr_word);
            ptr_word++;
        }
        printf("%s\n", *ptr_word);
    }
}
