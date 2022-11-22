#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// struct Queue {
//     int data;
//     struct Queue *next;
// };

// void printQueue(struct Queue *top){
//     while(top!=NULL){
//         printf("%d ", top->data);
//         top = top->next;
//     }
//     printf("\n");
// }

int main(){
    struct Queue *first, *second, *third, *rear;
    first = (struct Queue*)malloc(sizeof(struct Queue));
    second = (struct Queue*)malloc(sizeof(struct Queue));
    third = (struct Queue*)malloc(sizeof(struct Queue));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    rear = third;
    printQueue(first);
    printf("The element at the rear is %d\n", rear->data);
    return 0;
}