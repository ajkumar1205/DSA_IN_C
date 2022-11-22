struct Stack {
    long long data;
    struct Stack *next;
};

void printStack(struct Stack* );
void push(struct Stack** , long long );
long long peek(struct Stack* );
long long pop(struct Stack** );

void printStack(struct Stack *top){
    while(top!=NULL){
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void push(struct Stack **top, long long data){
    struct Stack *new;
    new = (struct Stack*)malloc(sizeof(struct Stack));
    new->data = data;
    new->next = (*top);
    (*top) = new;
}

long long peek(struct Stack *top){
    if(top==NULL){
        return -1;
    }
    return top->data;
}

long long pop(struct Stack **top){
    if((*top)==NULL){
        return -1;
    }
    long long data = (*top)->data;
    struct Stack *ptr = (*top);
    (*top) = (*top)->next;
    free(ptr);
    return data;
}