#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
int STACK[MAX], TOP;

void display(int []);
void PUSH(int [], int);
void POP (int []);
 
int main() {
    int ITEM = 0;
    int choice = 0;
    TOP = -1;
    for(int a = 0; a < 5; a++)
        PUSH(STACK, a);
    display(STACK);
    PUSH(STACK, 9);
    display(STACK);
    POP(STACK);
    display(STACK);
    POP(STACK);
    display(STACK);
    return 0;
}
 
void display(int stack[]) {
    int i = 0;
    if(TOP == -1) {
        printf("\nEmpty!");
        return;
    }
 
    printf("\nContent[STACK] - ");
    for(i = TOP; i >= 0; i--) {
        printf("%d ",stack[i]);
    }
}
 
void PUSH(int stack[], int item) {
    if(TOP == MAX-1) {
        printf("\nStack FULL!");
        return;
    }
    TOP++;
    stack[TOP] = item;
    printf("\n%d Inserted!", item);
}
 
void POP(int stack[]) {
    int deletedItem;
    if(TOP == -1) {
        printf("\nEmpty!");
        return;
    }
    deletedItem = stack[TOP];
    TOP--;
    printf("\n%d Deleted!", deletedItem);
    return;
}
