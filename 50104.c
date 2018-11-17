#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

#define MAXN 5000
#define MAXM 1000
#define MAXLEN 41

// BST starts here
typedef struct node2{
    char name[MAXLEN];
    struct node2 *left;
    struct node2 *right;
} MemberNode;
typedef struct node1{
    char name[MAXLEN];
    char leader[MAXLEN];
    MemberNode *members;
    struct node1 *left;
    struct node1 *right;
} ClubNode;

MemberNode* insert_member(MemberNode *root, char stuname[MAXLEN]){
    if(root == NULL){
        root = (MemberNode*)malloc(sizeof(MemberNode));
        assert(root != NULL);
        strcpy(root->name, stuname);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(strcmp(stuname, root->name) < 0) root->left = insert_member(root->left, stuname);
    else                            root->right = insert_member(root->right, stuname);
    return root;
}
MemberNode* find_member(MemberNode *root, char stuname[MAXLEN]){
    if(root == NULL) return NULL;
    if(strcmp(stuname, root->name) == 0) return root;
    if(strcmp(stuname, root->name) < 0) return find_member(root->left, stuname);
    else                            return find_member(root->right, stuname);
}
ClubNode* create_club(ClubNode *root, char clubname[MAXLEN], char leader[MAXLEN]){
    if(root == NULL){
        root = (ClubNode*)malloc(sizeof(ClubNode));
        assert(root != NULL);
        strcpy(root->name, clubname);
        strcpy(root->leader, leader);
        root->members = NULL;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(strcmp(clubname, root->name) < 0) root->left = create_club(root->left, clubname, leader);
    else                             root->right = create_club(root->right, clubname, leader);
    return root;
}
ClubNode* find_club(ClubNode *root, char clubname[MAXLEN]){
    if(root == NULL) return NULL;
    if(strcmp(clubname, root->name) == 0) return root;
    if(strcmp(clubname, root->name) < 0) return find_club(root->left, clubname);
    else                             return find_club(root->right, clubname);
}
// BST ends here


int main(){
    ClubNode *root = NULL;
    int K;
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        int q;
        char stu[MAXLEN], clu[MAXLEN];
        scanf("%d%s%s", &q, stu, clu);
        ClubNode *tmp;
        switch(q){
            case 0:
                root = create_club(root, clu, stu);
                break;
            case 1:
                tmp = find_club(root, clu);
                tmp->members = insert_member(tmp->members, stu);
                break;
        }
    }

    int Q;
    scanf("%d", &Q);
    while(Q--){
        int q;
        scanf("%d", &q);
        char clu[MAXLEN], stu[MAXLEN];
        ClubNode *tmp;
        MemberNode *tmp2;
        switch(q){
            case 0:
                scanf("%s", clu);
                tmp = find_club(root, clu);
                if(tmp == NULL) printf("None\n");
                else            printf("%s\n", tmp->leader);
                break;
            case 1:
                scanf("%s%s", stu, clu);
                tmp = find_club(root, clu);
                if(tmp == NULL) printf("-1\n");
                else{
                    tmp2 = find_member(tmp->members, stu);
                    if(tmp2 != NULL) printf("1\n");
                    else if(strcmp(tmp->leader, stu) == 0) printf("1\n");
                    else printf("0\n");
                }
                break;
        }
    }

#ifdef DEBUG
    printf("press ctrl+C to exit ...\n");
    while(1);
#endif
    return 0;
}
