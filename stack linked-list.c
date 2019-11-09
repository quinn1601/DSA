#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int info;
    struct node *ptr;
}typedef node;

node *top = NULL, *top1, *temp;
 
void PUSH(int data);
void POP();
void display();
void destroy();
 
int count = 0;
 
int main() {
    for(int a = 0; a < 5; a++)
        PUSH(a);
    display();
    PUSH(9);
    display();
    POP();
    display();
    POP();
    display();
    destroy();
    return 0;
}
 
void PUSH(int data) {
    if (top == NULL) {
        top = (node *)malloc(1*sizeof(node));
        top->ptr = NULL;
        top->info = data;
    }
    else {
        temp =(node *)malloc(1*sizeof(node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("\n%d Inserted!", data);
}
 
void display() {
    top1 = top;
    printf("\nContent[STACK] - ");
    if (top1 == NULL) {
        printf("\nEmpty!");
        return;
    }
 
    while(top1 != NULL) {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
}
 
void POP() {
    top1 = top;
    if (top1 == NULL) {
        printf("\nEmpty!");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n%d Deleted!", top->info);
    free(top);
    top = top1;
    count--;
}
 
void destroy() {
    top1 = top; 
    while (top1 != NULL) {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
    printf("\n#Destroyed!");
    count = 0;
}