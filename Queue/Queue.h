struct Queue {
    int data;
    struct Queue *next;
};

void printQueue(struct Queue* );
void push(struct Queue** , struct Queue** , int );
int peek(struct Queue* );
int pop(struct Queue** );

void printQueue(struct Queue *top){
    while(top!=NULL){
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void push(struct Queue **top, struct Queue **rear, int data){
    struct Queue *new;
    new = (struct Queue*)malloc(sizeof(struct Queue));
    new->data = data;
    new->next = NULL;
    if((*top)==NULL){
        (*top) = new;
        (*rear) = new;
    }else{
        (*rear)->next = new;
        (*rear) = new;
    }
}

int peek(struct Queue *top){
    if(top==NULL){
        return -1;
    }
    return top->data;
}

int pop(struct Queue **top){
    if((*top)==NULL){
        return -1;
    }
    int data = (*top)->data;
    struct Queue *ptr = (*top);
    (*top) = (*top)->next;
    free(ptr);
    return data;
}