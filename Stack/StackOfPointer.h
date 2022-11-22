struct StackOfPointer {
    struct BinaryTree *address;
    struct StackOfPointer *next;
};

// void printStackOfPointer(struct StackOfPointer* );
void push(struct StackOfPointer** , struct BinaryTree* );
struct BinaryTree* peek(struct StackOfPointer* );
struct BinaryTree* pop(struct StackOfPointer** );

// void printStackOfPointer(struct StackOfPointer *top){
//     while(top!=NULL){
//         printf("%d ", top->address->data);
//         top = top->next;
//     }
//     printf("\n");
// }

void push(struct StackOfPointer **top, struct BinaryTree *address){
    struct StackOfPointer *ptr;
    ptr = (struct StackOfPointer*)malloc(sizeof(struct StackOfPointer));
    ptr->address = address;
    ptr->next = (*top);
    (*top) = ptr;
}

struct BinaryTree* peek(struct StackOfPointer *top){
    if(top==NULL){
        return NULL;
    }
    return top->address;
}

struct BinaryTree* pop(struct StackOfPointer **top){
    if((*top)==NULL){
        return NULL;
    }
    struct BinaryTree *address = (*top)->address;
    struct StackOfPointer *ptr = (*top);
    (*top) = (*top)->next;
    free(ptr);
    return address;
}