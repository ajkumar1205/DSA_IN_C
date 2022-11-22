#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// void insertAt(struct LinkedList **head, int index, int data){
//     if(index==0){
//         insert(head, data);
//         return;
//     }
//     struct LinkedList *new;
//     new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
//     new->data = data;
//     struct LinkedList *ptr = *head;
//     while(ptr!=NULL&&index>1&&ptr->next!=NULL){
//         index--;
//         ptr =  ptr->next;
//     }
//     new->next = ptr->next;
//     ptr->next = new;
// }

int main(){
    struct LinkedList *head = NULL;
    insert(&head, 900);
    insert(&head, 800);
    insert(&head, 700);
    insert(&head, 500);
    insert(&head, 400);
    insert(&head, 200);
    insertAt(&head, 0, 100);
    insertAt(&head, 2, 300);
    insertAt(&head, 1, 150);
    insertAt(&head, 20, 1000);
    insertAt(&head, 9, 950);
    insertAt(&head, 11, 1100);
    printList(head);
    return 0;
}