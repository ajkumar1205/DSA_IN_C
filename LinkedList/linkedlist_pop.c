#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// int pop(struct LinkedList **head){
//     struct LinkedList *ptr = (*head);
//     struct LinkedList *prevptr = (*head);
//     while(ptr!=NULL){
//         ptr = ptr->next;
//         if(ptr->next==NULL){
//             break;
//         }
//         prevptr = prevptr->next;
//     }
//     prevptr->next = NULL;
//     int data = ptr->data;
//     free(ptr);
//     return data;
// }

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    struct LinkedList *head = LinkedList(arr, 8);
    printList(head);
    pop(&head);
    printList(head);
    return 0;
}