// upload start here
#include <stdio.h>
#include "node.h"
#define MAXDEP 1000+1
void DFS(struct node *current, int depth, int arr[MAXDEP]){
    arr[depth++] = current->data;
    if(current->left==NULL && current->right==NULL){
        for(int i=0; i<depth; i++) printf("%d%c", arr[i], ((i!=depth-1)?' ':'\n'));
        return;
    }
    if(current->left != NULL) DFS(current->left, depth, arr);
    if(current->right != NULL) DFS(current->right, depth, arr);
}
void print_all_paths(struct node *root){
    int arr[MAXDEP];
    DFS(root, 0, arr);
}
// upload ends here
