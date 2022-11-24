#include "..\Stack\StackOfBST.h"
#include <time.h>

struct BinarySearchTree {
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
};

void printPreOrderBST(struct BinarySearchTree* );
// struct BinarySearchTree* createBinaryTree(int , int );
void printInOrderBST(struct BinarySearchTree* );
void printPostOrderBST(struct BinarySearchTree* );

void printPreOrderBST(struct BinarySearchTree *root){
    struct StackOfBST *top = NULL;
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

// struct BinarySearchTree* createBinaryTree(int leftNodes, int rightNodes){
//     srand(time(0));
//     struct BinarySearchTree *root = NULL;
//     root = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
//     root->data = (rand()%rand())%251;
//     struct StackOfBST *left = NULL;
//     struct StackOfBST *right = NULL;
//     for(int i=1;i<=leftNodes;i++){
//         struct BinarySearchTree *new = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
//         new = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
//         new->data = (rand()%rand())%251;
//         new->left = NULL;
//         new->right = NULL;
//         push(&left, new);
//     }
//     for(int i=1;i<=rightNodes;i++){
//         struct BinarySearchTree *new = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
//         new = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
//         new->data = (rand()%rand())%251;
//         new->left = NULL;
//         new->right = NULL;
//         push(&right, new);
//     }
//     struct BinarySearchTree *ptr1 = root;
//     struct BinarySearchTree *ptr2 = root;
//     ptr1->left = pop(&left);
//     ptr1 = ptr1->left;
//     while(left!=NULL){
//         struct BinarySearchTree *backup = ptr1;
//         if(rand()%2==0){
//             ptr1->left = pop(&left);
//             ptr1 = ptr1->left;
//             if(rand()%2==1){
//                 backup->right = pop(&left);
//             }
//         }else{
//             ptr1->right = pop(&left);
//             ptr1 = ptr1->right;
//             if(rand()%2==0){
//                 backup->left = pop(&left);
//             }
//         }
//     }
//     ptr2->right = pop(&right);
//     ptr2 = ptr2->right;
//     while(right!=NULL){
//         struct BinarySearchTree *backup = ptr2;
//         if(rand()%2==0){
//             ptr2->left = pop(&right);
//             ptr2 = ptr2->left;
//             if(rand()%2==1){
//                 backup->right = pop(&right);
//             }
//         }else{
//             ptr2->right = pop(&right);
//             ptr2 = ptr2->right;
//             if(rand()%2==0){
//                 backup->left = pop(&right);
//             }
//         }
//     }
//     return root;
// }

void printInOrderBST(struct BinarySearchTree *root){
    struct StackOfBST *top = NULL;
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

// DOESN'T WORK PROPERLY WHEN DUPLICATES OCCURS AT SPECIFIC SET OF NODES
void printPostOrderBST(struct BinarySearchTree *root){
    struct StackOfBST *mainStack = NULL;
    struct StackOfBST *right = NULL;
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
            if(right!=NULL&&root->data==peek(right)->data){
                pop(&right);
                pop(&mainStack);
                break;
            }
            printf("%d ", root->data);
            pop(&mainStack);
            root = peek(mainStack);
        }
    }
}