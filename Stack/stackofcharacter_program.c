#include <stdio.h>
#include <stdlib.h>
#include "StackOfCharacter.h"
#define SOC struct StackOfCharacter

int main(){
    SOC *top = NULL;
    push(&top, 'Y');
    push(&top, 'A');
    push(&top, 'J');
    push(&top, 'A');
    printf("The peeked character is %c\n", peek(top));
    printStackOfCharacter(top);
    printf("Popped character is %c\n", pop(&top));
    printStackOfCharacter(top);
    printf("Popped character is %c\n", pop(&top));
    printStackOfCharacter(top);
    printf("Popped character is %c\n", pop(&top));
    printStackOfCharacter(top);
    return 0;
}