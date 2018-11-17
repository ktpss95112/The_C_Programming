#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

#define MAXEXP 2000
#define MAXVAR 32+1

typedef struct node{
    char data[MAXVAR];
    struct node *left;
    struct node *right;
} Node;

// for debug usage
void print_bst(Node *root){
    if(root == NULL) return;
    print_bst(root->left);
    printf("%s ", root->data);
    print_bst(root->right);
}

Node* construct_opeartor();
Node* construct_number(char first);
void substitute(Node *root, char name[MAXVAR], char value[MAXVAR]);
int DFS(Node *root);

int main(){
    char c=getchar();
    if(c != '('){
        do{
            printf("%c", c);
        } while(scanf("%c", &c) != EOF);
        return 0;
    }
    Node *root = construct_opeartor();

    char name[MAXVAR], value[MAXVAR];
    while(scanf("%s = %s", name, value) != EOF){
        substitute(root, name, value);
    }
    printf("%d\n", DFS(root));

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}


Node* construct_opeartor(){
    Node *current = (Node*)malloc(sizeof(Node));

    // get operator
    getchar(); // get blank
    current->data[0] = getchar();
    current->data[1] = '\0';

    // get left tree
    getchar(); // get blank
    char left = getchar();
    if(left == '(') current->left = construct_opeartor();
    else            current->left = construct_number(left);

    // get right tree
    char right = getchar();
    if(right == '(') current->right = construct_opeartor();
    else             current->right = construct_number(right);

    // consume ')'
    getchar(); // get ')'
    getchar(); // get blank
    return current;
}
Node* construct_number(char first){
    Node *current = (Node*)malloc(sizeof(Node));
    int i=0;
    for( ; first!=' '; i++){
        current->data[i] = first;
        first = getchar();
    }
    current->data[i] = '\0';
    current->left = NULL;
    current->right = NULL;
    return current;
}
void substitute(Node *root, char name[MAXVAR], char value[MAXVAR]){
    if(root == NULL) return;
    if(strcmp(root->data, name) == 0){
        sprintf(root->data, "%s", value);
        return;
    }
    substitute(root->left, name, value);
    substitute(root->right, name, value);
}
int DFS(Node *root){
    if(root->left == NULL) return atoi(root->data);
    int left = DFS(root->left);
    int right = DFS(root->right);
    int ans;
    switch(root->data[0]){
        case '+':
            ans = left+right;
            break;
        case '-':
            ans = left-right;
            break;
        case '*':
            ans = left*right;
            break;
        case '/':
            ans = left/right;
            break;
    }
    return ans;
}
