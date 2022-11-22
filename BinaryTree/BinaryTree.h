#include "..\Stack\StackOfPointer.h"
#include <time.h>

struct BinaryTree {
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

void printPreOrderTree(struct BinaryTree* );
struct BinaryTree* createBinaryTree(int , int );
void printInOrderTree(struct BinaryTree* );

void printPreOrderTree(struct BinaryTree *root){
    struct StackOfPointer *top = NULL;
    while(root!=NULL){
        printf("%d ", root->data);
        if(root->right!=NULL){
            push(&top, root->right);
        }
        if(root->left!=NULL){
            root = root->left;
        }else{
            root = pop(&top);
        }
    }
}

struct BinaryTree* createBinaryTree(int leftNodes, int rightNodes){
    srand(time(0));
    struct BinaryTree *root = NULL;
    root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    root->data = rand()%150;
    struct StackOfPointer *left = NULL;
    struct StackOfPointer *right = NULL;
    for(int i=1;i<=leftNodes;i++){
        struct BinaryTree *new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new->data = rand()%47;
        new->left = NULL;
        new->right = NULL;
        push(&left, new);
    }
    for(int i=1;i<=rightNodes;i++){
        struct BinaryTree *new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        new->data = rand()%37;
        new->left = NULL;
        new->right = NULL;
        push(&right, new);
    }
    struct BinaryTree *ptr1 = root;
    struct BinaryTree *ptr2 = root;
    ptr1->left = pop(&left);
    ptr1 = ptr1->left;
    while(left!=NULL){
        struct BinaryTree *backup = ptr1;
        if(rand()%2==0){
            ptr1->left = pop(&left);
            ptr1 = ptr1->left;
            if(rand()%2==1){
                backup->right = pop(&left);
            }
        }else{
            ptr1->right = pop(&left);
            ptr1 = ptr1->right;
            if(rand()%2==0){
                backup->left = pop(&left);
            }
        }
    }
    ptr2->right = pop(&right);
    ptr2 = ptr2->right;
    while(right!=NULL){
        struct BinaryTree *backup = ptr2;
        if(rand()%2==0){
            ptr2->left = pop(&right);
            ptr2 = ptr2->left;
            if(rand()%2==1){
                backup->right = pop(&right);
            }
        }else{
            ptr2->right = pop(&right);
            ptr2 = ptr2->right;
            if(rand()%2==0){
                backup->left = pop(&right);
            }
        }
    }
    return root;
}

void printInOrderTree(struct BinaryTree *root){
    struct StackOfPointer *top = NULL;
    while(root!=NULL){
        while(root!=NULL){
            push(&top, root);
            root = root->left;
        }
        root = pop(&top);
        while(root!=NULL){
            printf("%d ", root->data);
            if(root->right!=NULL){
                root = root->right;
                break;
            }
            root = pop(&top);
        }
    }
}