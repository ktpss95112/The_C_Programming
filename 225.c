#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct{
    unsigned int id;
    char name[32];
} Person;
typedef struct{
    unsigned id1;
    unsigned id2;
} Friends;

Person person[10000];
Friends friends[10000];

int main(){
    FILE *fin = fopen("friends", "rb");
    assert(fin != NULL);

    int p;
    fread(&p, 4, 1, fin);
    fread(person, sizeof(Person), p, fin);
    int f;
    fread(&f, 4, 1, fin);
    fread(friends, sizeof(Friends), f, fin);

    char command[70];
    while(fgets(command, 70, stdin) != NULL){
        if(command[0]=='e' && command[1]=='n' && command[2]=='d' && command[3]=='\n') break;
        char name1[50], name2[50];
        sscanf(command, "%s %s", name1, name2);
        unsigned int id1, id2;
        for(int i=0; i<p; i++){
            if(strcmp(name1, person[i].name) == 0) id1 = person[i].id;
            if(strcmp(name2, person[i].name) == 0) id2 = person[i].id;
        }
        int yes_flag = 0;
        for(int i=0; i<f; i++){
            if(id1==friends[i].id1 && id2==friends[i].id2) yes_flag = 1;
            if(id2==friends[i].id1 && id1==friends[i].id2) yes_flag = 1;
        }
        if(yes_flag) printf("yes\n");
        else         printf("no\n");
    }

    fclose(fin);
    return 0;
}
