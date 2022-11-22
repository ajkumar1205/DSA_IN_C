#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// int deleteThis(struct LinkedList **head, int data){
//     if((*head)==NULL){
//         return -1;
//     }
//     struct LinkedList *ptr = (*head);
//     if(ptr->data==data){
//         return delete(head);
//     }
//     struct LinkedList *prevptr = (*head);
//     while(ptr!=NULL&&ptr->next!=NULL){
//         ptr = ptr->next;
//         if(ptr->data==data){
//             break;
//         }
//         prevptr = prevptr->next;
//     }
//     int dt = ptr->data;
//     prevptr->next = ptr->next;
//     free(ptr);
//     return dt;
// }

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    struct LinkedList *head = LinkedList(arr, 7);
    printList(head);
    deleteThis(&head, 1);
    printList(head);
    deleteThis(&head, 4);
    printList(head);
    deleteThis(&head, 7);
    printList(head);
    return 0;
}