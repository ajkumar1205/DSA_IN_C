#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// struct LinkedList {
//     int data;
//     struct LinkedList *next;
// };

// void printList(struct LinkedList *head){
//     while(head!=NULL){
//         printf("%d ->", head->data);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

int main(){
    struct LinkedList *head, *second, *third;
    head = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    second = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    third = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printList(head);
    return 0;
}