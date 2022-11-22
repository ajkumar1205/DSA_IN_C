#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// void push(struct Queue **top, struct Queue **rear, int data){
//     struct Queue *new;
//     new = (struct Queue*)malloc(sizeof(struct Queue));
//     new->data = data;
//     new->next = NULL;
//     if((*top)==NULL){
//         (*top) = new;
//         (*rear) = new;
//     }else{
//         (*rear)->next = new;
//         (*rear) = new;
//     }
// }

int main(){
    struct Queue *top = NULL, *rear;
    push(&top, &rear, 10);
    push(&top, &rear, 20);
    push(&top, &rear, 30);
    push(&top, &rear, 40);
    push(&top, &rear, 50);
    push(&top, &rear, 60);
    printQueue(top);
    printf("The element at rear pointer is %d\n", rear->data);
    return 0;
}