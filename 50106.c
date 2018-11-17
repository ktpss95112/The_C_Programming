// construct.c starts here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "construct.h"
int compar(Node *root, char name[16], int height, int weight){
#ifdef HEIGHT
    if(height < root->height) return -1;
    return 1;
#endif
#ifdef WEIGHT
    if(weight < root->weight) return -1;
    return 1;
#endif
}
Node* insert(Node *root, char name[16], int height, int weight){
    if(root == NULL){
        Node *root = (Node*)malloc(sizeof(Node));
        strcpy(root->name, name);
        root->height = height;
        root->weight = weight;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(compar(root, name, height, weight) < 0) root->left = insert(root->left, name, height, weight);
    else                                       root->right = insert(root->right, name, height, weight);
    return root;
}
Node* ConstructBSTree(int N, char name[][16], int height[], int weight[]){
    Node *root = NULL;
    for(int i=0; i<N; i++){
        root = insert(root, name[i], height[i], weight[i]);
    }
    return root;
}
// construct.c ends here
