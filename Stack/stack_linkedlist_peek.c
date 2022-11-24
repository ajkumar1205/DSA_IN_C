#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// int peek(struct Stack *top){
//     if(top==NULL){
//         return -1;
//     }
//     return top->data;
// }

int main(){
    struct Stack *top = NULL;
    push(&top, 90);
    push(&top, 80);
    push(&top, 70);
    push(&top, 60);
    push(&top, 50);
    push(&top, 40);
    push(&top, 30);
    push(&top, 20);
    printStack(top);
    printf("The peeked value is %d\n", peek(top));
    return 0;
}