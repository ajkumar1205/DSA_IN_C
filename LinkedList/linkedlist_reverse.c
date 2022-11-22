#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void reverseList(struct LinkedList **head){
    if((*head)==NULL||(*head)->next==NULL){
        return;
    }
    struct LinkedList *prev = (*head);
    (*head) = (*head)->next;
    prev->next = NULL;
    if((*head)->next==NULL){
        (*head)->next = prev;
        return;
    }
    struct LinkedList *next = (*head)->next;
    while(next!=NULL){
        (*head)->next = prev;
        prev = (*head);
        (*head) = next;
        next = next->next;
    }
    (*head)->next = prev;
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct LinkedList *head = LinkedList(arr, 10);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}