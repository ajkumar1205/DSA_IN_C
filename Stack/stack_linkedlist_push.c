#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// void push(struct Stack **top, int data){
//     struct Stack *new;
//     new = (struct Stack*)malloc(sizeof(struct Stack));
//     new->data = data;
//     new->next = (*top);
//     (*top) = new;
// }

int main(){
    struct Stack *top = NULL;
    push(&top, 70);
    push(&top, 60);
    push(&top, 50);
    push(&top, 40);
    push(&top, 30);
    push(&top, 20);
    push(&top, 10);
    printStack(top);
    return 0;
}