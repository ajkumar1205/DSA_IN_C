#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// struct Stack {
//     int data;
//     struct Stack *next;
// };

// void printStack(struct Stack *top){
//     while(top!=NULL){
//         printf("%d ", top->data);
//         top = top->next;
//     }
//     printf("\n");
// }

int main(){
    struct Stack *first, *second, *third;
    first = (struct Stack*)malloc(sizeof(struct Stack));
    second = (struct Stack*)malloc(sizeof(struct Stack));
    third = (struct Stack*)malloc(sizeof(struct Stack));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    printStack(first);
    return 0;
}