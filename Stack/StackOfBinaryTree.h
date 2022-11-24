struct StackOfBinaryTree {
    struct BinaryTree *address;
    struct StackOfBinaryTree *next;
};

// void printStackOfPointer(struct StackOfBinaryTree* );
void push(struct StackOfBinaryTree** , struct BinaryTree* );
struct BinaryTree* peek(struct StackOfBinaryTree* );
struct BinaryTree* pop(struct StackOfBinaryTree** );

// void printStackOfPointer(struct StackOfBinaryTree *top){
//     while(top!=NULL){
//         printf("%d ", top->address->data);
//         top = top->next;
//     }
//     printf("\n");
// }

void push(struct StackOfBinaryTree **top, struct BinaryTree *address){
    struct StackOfBinaryTree *ptr;
    ptr = (struct StackOfBinaryTree*)malloc(sizeof(struct StackOfBinaryTree));
    ptr->address = address;
    ptr->next = (*top);
    (*top) = ptr;
}

struct BinaryTree* peek(struct StackOfBinaryTree *top){
    if(top==NULL){
        return NULL;
    }
    return top->address;
}

struct BinaryTree* pop(struct StackOfBinaryTree **top){
    if((*top)==NULL){
        return NULL;
    }
    struct BinaryTree *address = (*top)->address;
    struct StackOfBinaryTree *ptr = (*top);
    (*top) = (*top)->next;
    free(ptr);
    return address;
}