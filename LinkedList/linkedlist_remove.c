#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// int delete(struct LinkedList **head){
//     if((*head)==NULL){
//         return -1;
//     }
//     int data = (*head)->data;
//     struct LinkedList *ptr = (*head);
//     (*head) = (*head)->next;
//     free(ptr);
//     return data;
// }

int main(){
    struct LinkedList *head = NULL;
    insert(&head, 500);
    insert(&head, 400);
    insert(&head, 300);
    insert(&head, 200);
    insert(&head, 100);
    insert(&head, 50);
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    printList(head);
    printf("The deleted node is %d\n", delete(&head));
    return 0;
}