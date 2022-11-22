struct StackOfCharacter {
    char data;
    struct StackOfCharacter *next;
};

void printStackOfCharacter(struct StackOfCharacter* );
void push(struct StackOfCharacter** , char );
char peek(struct StackOfCharacter* );
char pop(struct StackOfCharacter** );

void printStackOfCharacter(struct StackOfCharacter *top){
    while(top!=NULL){
        printf("%c ", top->data);
        top = top->next;
    }
    printf("\n");
}

void push(struct StackOfCharacter **top, char data){
    struct StackOfCharacter *new;
    new = (struct StackOfCharacter*)malloc(sizeof(struct StackOfCharacter));
    new->data = data;
    new->next = (*top);
    (*top) = new;
}

char peek(struct StackOfCharacter *top){
    if(top==NULL){
        return -1;
    }
    return top->data;
}

char pop(struct StackOfCharacter **top){
    if((*top)==NULL){
        return -1;
    }
    int data = (*top)->data;
    struct StackOfCharacter *ptr = (*top);
    (*top) = (*top)->next;
    free(ptr);
    return data;
}