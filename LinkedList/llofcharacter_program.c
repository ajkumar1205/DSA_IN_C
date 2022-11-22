#include <stdio.h>
#include <stdlib.h>
#include "LLOfCharacter.h"
#define String struct LLOfCharacter

int main(){
    char arr[10] = "abcdefghij";
    String *head = LLOfCharacter(arr, 10);
    printLLOfCharacter(head);
    insert(&head, 'i');
    printLLOfCharacter(head);
    insertAt(&head, 5, 'Z');
    printLLOfCharacter(head);
    deleteThis(&head, 'Z');
    printLLOfCharacter(head);
    delete(&head);
    printLLOfCharacter(head);
    pop(&head);
    printLLOfCharacter(head);
    append(&head, 'Z');
    printLLOfCharacter(head);
    printf("The Length of the LinkedListOfCharacter is %d\n", length(head));
    return 0;
}