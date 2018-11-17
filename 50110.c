// operations.c starts here
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
Node *FlipTree(Node *root){
    if(root == NULL) return NULL;
    Node *current = (Node*)malloc(sizeof(Node));
    current->n = root->n;
    current->left = FlipTree(root->right);
    current->right = FlipTree(root->left);
    return current;
}
int isIdentical(Node *tree1, Node *tree2){
    if(tree1==NULL && tree2==NULL) return 1;
    if(tree1==NULL || tree2==NULL) return 0;
    if(tree1->n != tree2->n) return 0;
    return (isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right));
}
void calc(Node *root, int *sum_of_depth, int *num_of_leaf, int depth){
    if(root == NULL) return;
    if(root->left==NULL && root->right==NULL){
        *sum_of_depth += depth;
        *num_of_leaf += 1;
        return;
    }
    calc(root->left, sum_of_depth, num_of_leaf, depth+1);
    calc(root->right, sum_of_depth, num_of_leaf, depth+1);
}
void depthAvg(Node *root){
    int sum_of_depth=0, num_of_leaf=0;
    calc(root, &sum_of_depth, &num_of_leaf, 0);
    printf("%d/%d\n", sum_of_depth, num_of_leaf);
}
// operations.c ends here
