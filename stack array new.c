#include<stdio.h>
#include<stdlib.h>

struct Stack {                    //Stack Structure
    int size;
    int top;
    int *s;
} typedef stack;

void Create(stack *st, int size) {//Init. the Stack with the Given Size
    st->size = size;
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void Display(stack st) {          //Displays the Stack from Top -> Bottom
    for(int a = st.top; a >= 0; a--)
        printf("%d ", st.s[a]);
}

void Push(stack *st, int num) {   //Pushes the stack and Inserts the Element to the Top
    if(st->top == st->size - 1)
        printf("ERROR: Stack Overflow!");
    else {
        st->top++;
        st->s[st->top] = num;
    }
}

int Pop(stack *st) {              //Pops the Stack and Deletes the Top Element
    int pop = -1;
    if(st->top == -1)
        printf("ERROR: Stack Underflow!");
    else 
        pop = st->s[st->top--];
    return pop;
}

int Peek(stack st, int index) {   //Returns the Element from the stack with the Given Index
    int x = -1;
    if(st.top - index+1 < 0)
        printf("ERROR: Invalid Index!");
    else
        x = st.s[st.top-index+1];
    return x;
}

int IsEmpty(stack st) {           //Checks if Stack is Full or Not
    if(st.top == -1)
        return 1;
    return 0;
}

int IsFull(stack st) {            //Checks if Stack is Full or Not
    return (st.top == st.size - 1);
}

int StackTop(stack st) {          //Returns Top Element of the Stack
    if(!IsEmpty(st))
        return st.s[st.top];
    return -1;
}



int main() {
    stack s;
    Create(&s, 5);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    printf("\nStack Content - "); Display(s);
    printf("\nPopped Element - %d", Pop(&s)); 
    printf("\nStack Content - "); Display(s);
    Push(&s, 6);
    printf("\nStack Content - "); Display(s);
    printf("\nIs Empty Status - %d", IsEmpty(s));
    printf("\nIs Full Status - %d", IsFull(s));
    printf("\nStack Top - %d", StackTop(s));
    printf("\nElement at index [2] - %d", Peek(s, 2));
    return 0;
}