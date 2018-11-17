// construct.c starts here
#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

Node* no_bp(int T[], int l, int r){
    if(l == r) return NULL;
    Node *current = (Node*)malloc(sizeof(Node));
    current->value = T[r-1];
    current->right = NULL;
    current->left = no_bp(T, l, r-1);
    return current;
}
Node* find_balanced_point(int T[], int l, int r){
    if(r-l < 3) return no_bp(T, l, r);

    int bp = -1;
    for(int i=l; i<r; i++){
        int l_torque=0, r_torque=0;
        for(int j=l; j<i; j++) l_torque += (i-j)*T[j];
        for(int j=i+1; j<r; j++) r_torque += (j-i)*T[j];
        if(l_torque == r_torque){
            bp = i;
            break;
        }
    }
    if(bp == -1) return no_bp(T, l, r);
    Node *current = (Node*)malloc(sizeof(Node));
    current->value = T[bp];
    current->left = find_balanced_point(T, l, bp);
    current->right = find_balanced_point(T, bp+1, r);
    return current;
}
Node* ConstructTree(int T[], int N){
    Node *root = find_balanced_point(T, 0, N);
    return root;
}
// construct.c ends here
