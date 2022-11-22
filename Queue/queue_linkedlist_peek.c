#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// int peek(struct Queue *top){
//     if(top==NULL){
//         return -1;
//     }
//     return top->data;
// }

int main(){
    struct Queue *top = NULL, *rear;
    push(&top, &rear, 10);
    push(&top, &rear, 20);
    push(&top, &rear, 30);
    push(&top, &rear, 40);
    push(&top, &rear, 50);
    printQueue(top);
    printf("The peeked value is %d\n", peek(top));
    return 0;
}