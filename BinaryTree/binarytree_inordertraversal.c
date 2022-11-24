#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h" 

// void printInOrderTree(struct BinaryTree *root){
//     struct StackOfPointer *top = NULL;
//     while(root!=NULL){
//         while(root!=NULL){
//             push(&top, root);
//             root = root->left;
//         }
//         root = pop(&top);
//         while(root!=NULL){
//             printf("%d ", root->data);
//             if(root->right!=NULL){
//                 root = root->right;
//                 break;
//             }
//             root = pop(&top);
//         }
//     }
//     printf("\n");
// }

int main(){
    struct BinaryTree *root = createBinaryTree(7, 7);
    printPreOrderTree(root);
    printf("\n");
    printInOrderTree(root);
    return 0;
}