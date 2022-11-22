#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void printPostOrderTree(struct BinaryTree *root){
    struct StackOfPointer *mainStack = NULL;
    struct StackOfPointer *right = NULL;
    while(root!=NULL){
        while(root!=NULL){
            push(&mainStack, root);
            if(root->right!=NULL){
                push(&mainStack, root->right);
                push(&right, root->right);
            }
            root = root->left;
        }
        root = peek(mainStack);
        while(root!=NULL){
            if(root->data==peek(right)->data){
                pop(&right);
                pop(&mainStack);
                break;
            }
            printf("%d ", pop(&mainStack)->data);
            root = pop(&mainStack);
        }
    }
}

int main(){
    struct BinaryTree *root = createBinaryTree(4, 4);
    printPreOrderTree(root);
    printf("\n");
    printInOrderTree(root);
    printf("\n");
    printPostOrderTree(root);
    return 0;
}