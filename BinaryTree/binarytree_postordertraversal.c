#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// DOESN'T WORK PROPERLY WHEN DUPLICATES OCCURS AT SPECIFIC SET OF NODES
// void printPostOrderTree(struct BinaryTree *root){
//     struct StackOfPointer *mainStack = NULL;
//     struct StackOfPointer *right = NULL;
//     while(root!=NULL){
//         while(root!=NULL){
//             push(&mainStack, root);
//             if(root->right!=NULL){
//                 push(&mainStack, root->right);
//                 push(&right, root->right);
//             }
//             root = root->left;
//         }
//         root = peek(mainStack);
//         while(root!=NULL){
//             if(right!=NULL&&root->data==peek(right)->data){
//                 pop(&right);
//                 pop(&mainStack);
//                 break;
//             }
//             printf("%d ", root->data);
//             pop(&mainStack);
//             root = peek(mainStack);
//         }
//     }
// }

int main(){
    struct BinaryTree *root = createBinaryTree(7, 7);
    printPreOrderTree(root);
    printf("\n");
    printInOrderTree(root);
    printf("\n");
    printPostOrderTree(root);
    return 0;
}