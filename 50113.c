// construct.c starts here
#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

Node* insert(Node *root, int data){
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root->small = -1;
        root->large = data;
        root->left = NULL;
        root->mid = NULL;
        root->right = NULL;
        return root;
    }
    if(root->small == -1){
        if(data > root->large){
            root->small = root->large;
            root->large = data;
            return root;
        }
        root->small = data;
        return root;
    }
    if(data > root->large){
        root->right = insert(root->right, data);
        return root;
    }
    if(data > root->small){
        root->mid = insert(root->mid, data);
        return root;
    }
    if(data < root->small){
        root->left = insert(root->left, data);
        return root;
    }
}
Node* ConstructTree(int sequence[],int N){
    Node *root = NULL;
    for(int i=0; i<N; i++) root = insert(root, sequence[i]);
    return root;
}
// construct.c ends here
