struct StackOfBST {
    struct BinarySearchTree *address;
    struct StackOfBST *next;
};

// void printStackOfPointer(struct StackOfBST* );
void push(struct StackOfBST** , struct BinarySearchTree* );
struct BinarySearchTree* peek(struct StackOfBST* );
struct BinarySearchTree* pop(struct StackOfBST** );

// void printStackOfPointer(struct StackOfBST *top){
//     while(top!=NULL){
//         printf("%d ", top->address->data);
//         top = top->next;
//     }
//     printf("\n");
// }

void push(struct StackOfBST **top, struct BinarySearchTree *address){
    struct StackOfBST *ptr;
    ptr = (struct StackOfBST*)malloc(sizeof(struct StackOfBST));
    ptr->address = address;
    ptr->next = (*top);
    (*top) = ptr;
}

struct BinarySearchTree* peek(struct StackOfBST *top){
    if(top==NULL){
        return NULL;
    }
    return top->address;
}

struct BinarySearchTree* pop(struct StackOfBST **top){
    if((*top)==NULL){
        return NULL;
    }
    struct BinarySearchTree *address = (*top)->address;
    struct StackOfBST *ptr = (*top);
    (*top) = (*top)->next;
    free(ptr);
    return address;
}