#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// void append(struct LinkedList **head, int data){
//     if((*head)==NULL){
//         insert(head, data);
//         return;
//     }
//     struct LinkedList *new;
//     new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
//     new->data = data;
//     struct LinkedList *ptr = *head;
//     while(ptr!=NULL&&ptr->next!=NULL){
//         ptr =  ptr->next;
//     }
//     new->next = ptr->next;
//     ptr->next = new;
// }

int main(){
    struct LinkedList *head = NULL;
    append(&head, 300);
    append(&head, 400);
    insert(&head, 250);
    append(&head, 600);
    printList(head);
    return 0;
}