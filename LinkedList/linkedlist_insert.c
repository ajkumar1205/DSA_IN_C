#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// void insert(struct LinkedList **head, int data){
//     struct LinkedList *new;
//     new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
//     new->data = data;
//     new->next = (*head);
//     (*head) = new;
// }

int main(){
    struct LinkedList *head =  NULL;
    insert(&head, 200);
    insert(&head, 300);
    insert(&head, 500);
    insert(&head, 600);
    printList(head);
    return 0;
}