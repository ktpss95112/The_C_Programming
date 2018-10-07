#include <stdio.h>
void count(int **p[]){
    struct Node{
        int *pointer;
        int count;
        int number;
    } node[520];

    int n=0;
    //init
    for(int i=0; i<520; i++) node[i].count = -1;

    int times=0;
    for(int ***i=p; *i!=NULL; i++){
        times++;
        //check if exist
        int exist = 0;
        for(int j=0; j<n; j++){
            if(**i == node[j].pointer){
                node[j].count ++;
                exist = 1;
            }
        }
        if(!exist){
            node[n].pointer = **i;
            node[n].count = 1;
            node[n].number = ***i;
            n++;
        }
    }

    //sort
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            int swap=0;
            if(node[j].count > node[j+1].count) swap=1;
            else if(node[j].count == node[j+1].count){
                if(node[j].number > node[j+1].number) swap=1;
            }
            if(swap){
                int *tmpp = node[j].pointer;
                node[j].pointer = node[j+1].pointer;
                node[j+1].pointer = tmpp;

                int tmp = node[j].count;
                node[j].count = node[j+1].count;
                node[j+1].count = tmp;

                tmp = node[j].number;
                node[j].number = node[j+1].number;
                node[j+1].number = tmp;
            }
        }
    }

    //print
    for(int i=0; i<n; i++){
        printf("%d %d\n", node[i].number, node[i].count);
    }
}
