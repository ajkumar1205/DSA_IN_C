#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// int pop(struct Queue **top){
//     if((*top)==NULL){
//         return -1;
//     }
//     int data = (*top)->data;
//     struct Queue *ptr = (*top);
//     (*top) = (*top)->next;
//     free(ptr);
//     return data;
// }

int main(){
    struct Queue *top = NULL, *rear;
    push(&top, &rear, 10);
    push(&top, &rear, 20);
    push(&top, &rear, 30);
    push(&top, &rear, 40);
    push(&top, &rear, 50);
    printQueue(top);
    printf("The popped value is %d\n", pop(&top));
    printQueue(top);
    return 0;
}