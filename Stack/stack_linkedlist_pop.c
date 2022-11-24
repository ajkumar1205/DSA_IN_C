#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// int pop(struct Stack **top){
//     if((*top)==NULL){
//         return -1;
//     }
//     int data = (*top)->data;
//     struct Stack *ptr = (*top);
//     (*top) = (*top)->next;
//     free(ptr);
//     return data;
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
    printf("The poped value is %d\n", pop(&top));
    printStack(top);
    return 0;
}