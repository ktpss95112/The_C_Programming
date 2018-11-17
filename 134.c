#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

#define MAXN 1000

typedef struct input_pair{
    int num, depth;
} Input_pair;

typedef struct node{
    int data;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;

// for debug usage
void print_bst(Node *root){
    if(root == NULL) return;
    print_bst(root->left);
    printf("%d\n", root->data);
    print_bst(root->right);
}

int compar(const void *a, const void *b);
Node* insert(Node *root, Node *parent, int num);
void query(Node *root, int a, int b); // use flood fill to implement

int main(){
    int N;
    scanf("%d", &N);
    Input_pair in[MAXN];
    for(int i=0; i<N; i++) scanf("%d %d", &in[i].num, &in[i].depth);
    qsort(in, N, sizeof(Input_pair), compar);
    Node *root = NULL;
    for(int i=0; i<N; i++) root = insert(root, NULL, in[i].num);

    int q;
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        query(root, a, b);
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}

int compar(const void *a, const void *b){
    Input_pair *aa = (Input_pair*)a;
    Input_pair *bb = (Input_pair*)b;    
    if(aa->depth < bb->depth) return -1;
    if(aa->depth > bb->depth) return 1;
    if(aa->num < bb->num) return -1;
    if(aa->num > bb->num) return 1;
    return 0;
}
Node* insert(Node *root, Node *parent, int num){
    Node *current;
    if(root == NULL){
        current = (Node*)malloc(sizeof(Node));
        assert(current != NULL);
        current->data = num;
        current->parent = parent;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
    if(num < root->data) root->left = insert(root->left, root, num);
    else                 root->right = insert(root->right, root, num);
    return root;
}
Node* find(Node *root, int num){
    if(root->data == num) return root;
    return (num < root->data) ? find(root->left, num) : find(root->right, num);
}
int DFS(Node *root, Node *parent, int num){
    if(root == NULL) return -1;
    if(root->data == num) return 0;

    if(root->left != parent){
        int ans = DFS(root->left, root, num);
        if(ans != -1) return ans+1;
    }
    if(root->right != parent){
        int ans = DFS(root->right, root, num);
        if(ans != -1) return ans+1;
    }
    if(root->parent != parent){
        int ans = DFS(root->parent, root, num);
        if(ans != -1) return ans+1;
    }
    return -1;
}
void query(Node *root, int a, int b){ // use DFS to implement
    root = find(root, a);
    printf("%d\n", DFS(root, root, b));
}
