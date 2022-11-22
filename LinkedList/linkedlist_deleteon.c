#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// int deleteOn(struct LinkedList **head, int index){
//     if(index==0){
//         return delete(head);
//     }
//     struct LinkedList *ptr = (*head);
//     struct LinkedList *prevptr = (*head);
//     int pos = index;
//     int i=0;
//     while(ptr!=NULL&&ptr->next!=NULL){
//         pos--;
//         i++;
//         ptr = ptr->next;
//         if(pos==0){
//             break;
//         }
//         prevptr = prevptr->next;
//     }
//     if(i<index){
//         return -1;
//     }
//     int data = ptr->data;
//     prevptr->next = ptr->next;
//     free(ptr);
//     return data;
// }

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    struct LinkedList *head = LinkedList(arr, 5);
    printList(head);
    deleteOn(&head, 4);
    printList(head);
    deleteOn(&head, 3);
    printList(head);
    deleteOn(&head, 2);
    printList(head);
    deleteOn(&head, 1);
    printList(head);
    deleteOn(&head, 0);
    printList(head);
    return 0;
}