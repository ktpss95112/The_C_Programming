#include <stdio.h>
#include <stdlib.h>
 
#define bool int
#define true 1
#define false 0
 
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Node;
 
Node* construct();
void hlhr(Node *father);
void hrhl(Node *father);
 
// for debug usage
void print_bst(Node *root){
    if(root == NULL) return;
    print_bst(root->left);
    printf("%d\n", root->data);
    print_bst(root->right);
}
 
int main(){
    fgetc(stdin);
    Node *root = construct();
    hlhr(root);
 
#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
 
Node* construct(){
    char c = fgetc(stdin);
    Node *current = (Node*)malloc(sizeof(Node));
    if(c == '('){
        current->left = construct();
        fgetc(stdin);
    }
    else{
        char buffer[15];
        int i=0;
        while(c != ','){
            buffer[i++] = c;
            c = fgetc(stdin);
        }
        buffer[i] = '\0';
        current->left = (Node*)malloc(sizeof(Node));
        current->left->data = atoi(buffer);
        current->left->left = NULL;
        current->left->right = NULL;
    }
    c = fgetc(stdin);
    if(c == '('){
        current->right = construct();
        fgetc(stdin);
    }
    else{
        char buffer[15];
        int i=0;
        while(c != ')'){
            buffer[i++] = c;
            c = fgetc(stdin);
        }
        buffer[i] = '\0';
        current->right = (Node*)malloc(sizeof(Node));
        current->right->data = atoi(buffer);
        current->right->left = NULL;
        current->right->right = NULL;
    }
    current->data = current->left->data + current->right->data;
    return current;
}
void hlhr(Node *father){
    if(father == NULL) return;
    printf("%d\n", father->data);
    hrhl(father->left);
    printf("%d\n", father->data);
    hrhl(father->right);
}
void hrhl(Node *father){
    if(father == NULL) return;
    printf("%d\n", father->data);
    hlhr(father->right);
    printf("%d\n", father->data);
    hlhr(father->left);
}
