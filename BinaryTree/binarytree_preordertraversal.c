#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// void printPreOrderTree(struct BinaryTree *root){
//     struct StackOfPointer *top = NULL;
//     while(root!=NULL){
//         printf("%d ", root->data);
//         if(root->right!=NULL){
//             push(&top, root->right);
//         }
//         if(root->left!=NULL){
//             root = root->left;
//         }else{
//             root = pop(&top);
//         }
//     }
// }

int main(){
    struct BinaryTree *head, *left, *right, *lleft, *lright, *rleft;
    head = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    left = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    right = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    lleft = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    lright = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    rleft = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    head->data = 10;
    head->left = left;
    head->right = right;
    left->data = 15;
    left->left = lleft;
    left->right = lright;
    right->data = 20;
    right->left = rleft;
    right->right = NULL;
    lleft->data = 25;
    lleft->left = NULL;
    lleft->right = NULL;
    lright->data = 30;
    lright->left = NULL;
    lright->right = NULL;
    rleft->data = 35;
    rleft->left = NULL;
    rleft->right = NULL;
    printPreOrderTree(head);
    return 0;
}