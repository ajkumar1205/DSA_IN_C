#include "..\Stack\Stack.h"
#include <time.h>

struct BinaryTree {
    long long data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

void printPreOrderTree(struct BinaryTree* );
struct BinaryTree* createBinaryTree(int , int );
void printInOrderTree(struct BinaryTree* );

void printPreOrderTree(struct BinaryTree *root){
    struct Stack *top = NULL;
    while(root!=NULL){
        printf("%d ", root->data);
        if(root->right!=NULL){
            push(&top, (long long)root->right);
        }
        if(root->left!=NULL){
            root = root->left;
        }else{
            root = (struct BinaryTree*)pop(&top);
        }
    }
}

struct BinaryTree* createBinaryTree(int leftNodes, int rightNodes){
    srand(time(0));
    struct BinaryTree *root = NULL;
    root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    root->data = rand()%150;
    struct Stack *left = NULL;
    struct Stack *right = NULL;
    for(int i=1;i<=leftNodes;i++){
        struct BinaryTree *new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new->data = rand()%47;
        new->left = NULL;
        new->right = NULL;
        push(&left, (long long)new);
    }
    for(int i=1;i<=rightNodes;i++){
        struct BinaryTree *new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new->data = rand()%37;
        new->left = NULL;
        new->right = NULL;
        push(&right, (long long)new);
    }
    struct BinaryTree *ptr1 = root;
    struct BinaryTree *ptr2 = root;
    ptr1->left = (struct BinaryTree*)pop(&left);
    ptr1 = ptr1->left;
    while(left!=NULL){
        struct BinaryTree *backup = ptr1;
        if(rand()%2==0){
            ptr1->left = (struct BinaryTree*)pop(&left);
            ptr1 = ptr1->left;
            if(rand()%2==1){
                backup->right = (struct BinaryTree*)pop(&left);
            }
        }else{
            ptr1->right = (struct BinaryTree*)pop(&left);
            ptr1 = ptr1->right;
            if(rand()%2==0){
                backup->left = (struct BinaryTree*)pop(&left);
            }
        }
    }
    ptr2->right = (struct BinaryTree*)pop(&right);
    ptr2 = ptr2->right;
    while(right!=NULL){
        struct BinaryTree *backup = ptr2;
        if(rand()%2==0){
            ptr2->left = (struct BinaryTree*)pop(&right);
            ptr2 = ptr2->left;
            if(rand()%2==1){
                backup->right = (struct BinaryTree*)pop(&right);
            }
        }else{
            ptr2->right = (struct BinaryTree*)pop(&right);
            ptr2 = ptr2->right;
            if(rand()%2==0){
                backup->left = (struct BinaryTree*)pop(&right);
            }
        }
    }
    return root;
}

void printInOrderTree(struct BinaryTree *root){
    struct Stack *top = NULL;
    while(root!=NULL){
        while(root!=NULL){
            push(&top, (long long)root);
            root = root->left;
        }
        root = (struct BinaryTree*)pop(&top);
        while(root!=NULL){
            printf("%d ", root->data);
            if(root->right!=NULL){
                root = root->right;
                break;
            }
            root = (struct BinaryTree*)pop(&top);
        }
    }
}