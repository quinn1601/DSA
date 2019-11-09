#include <stdio.h>
#include <stdlib.h>

struct node {                                    //Definition of Linked-List Node
    int data;
    struct node *next;
}typedef node;

node *head;

void Array2List(int[], int);
void DisplayList(node *);
int ListLength(node *);
int SumOfList(node *);
int MaxNode(node *);
int MinNode(node *);
node *LinearSearch(node *, int);
node *Add2Top(node *, int);
void Add2End(node *, int);
void Add2Index(node *, int, int);
void Add2SortedList(node *, int);
void DeleteNode(node *, int);
int IsSorted(node *);
void RemoveDuplicates(node *);


int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11};
    Array2List(A, 10);
    printf("\nLength of the List is - %d", ListLength(head));
    printf("\nSum of the List is - %d", SumOfList(head));
    printf("\nMAX node is - %d", MaxNode(head));
    printf("\nMIN node is - %d", MinNode(head));
    printf("\nNode Address - %p", LinearSearch(head, 5));
    DisplayList(head);
    /*head = Add2Top(head, 0);
    DisplayList(head);
    Add2End(head, 11);
    DisplayList(head);
    Add2Index(head, 6, 0);*/
    Add2SortedList(head, 9);
    DisplayList(head);
    Add2SortedList(head, 12);
    DisplayList(head);
    head = Add2Top(head, 0);
    DisplayList(head);
    DeleteNode(head, 6);
    DisplayList(head);
    Add2Index(head, 6, 5);
    DisplayList(head);
    printf("\nIs List Sorted - %d", IsSorted(head));
    RemoveDuplicates(head);
    DisplayList(head);
    return 0;
}


void Array2List(int A[], int size) {             //Array to Linked-List Converter
    node *temp, *tail;
    head = (node *)malloc(sizeof(node));
    head->data = A[0];
    head->next = NULL;
    tail = head;
    for(int a = 1; a < size; a++) {
        temp = (node *)malloc(sizeof(node));
        temp->data = A[a];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void DisplayList(node *n) {                      //Display List using Iteration
    printf("\n");
    while(n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int ListLength(node *n) {                        //Length of List using Recursion
    if(n == NULL)
        return 0;
    else
        return ListLength(n->next) + 1;
}

int SumOfList(node *n) {                         //Sum of List using Recursion
    if(n == NULL)
        return 0;
    else 
        return n->data + SumOfList(n->next);
}

int MaxNode(node *n) {                           //MAX using Iteration
    int MAX = n->data;
    n = n->next;
    while(n != NULL) {
        MAX = (MAX > n->data)? MAX : n->data;
        n = n->next;
    }
    return MAX;
}

int MinNode(node *n) {                           //MIN using Iteration
    int MIN = n->data;
    n = n->next;
    while(n != NULL) {
        MIN = (MIN < n->data)? MIN : n->data;
        n = n->next;
    }
    return MIN;
}

node *LinearSearch(node *n, int Key) {           //Linear Search Using Iteration
    while(n != NULL) {
        if(n->data == Key)
            return n;
        n = n->next;
    }
    return NULL;
}

node *LinearSearchR(node *n, int Key) {          //Linear Search Using Recursion
    if(n == NULL);
        return NULL;
    if(n->data == Key)
        return n;
    return LinearSearchR(n->next, Key);
}

node *Add2Top(node *n, int Key) {                //Adding a Node to the TOP/HEAD of a Linked-List
    node *new = (node *)malloc(sizeof(node));
    new->data = Key;
    new->next = n;
    return new;
}

void Add2End(node *n, int Key) {                 //Adding a Node to the END/TAIL of a Linked-List
    node *new = (node *)malloc(sizeof(node));
    new->data = Key;
    new->next = NULL;
    while(n->next != NULL)
        n = n->next;
    n->next = new;
}

void Add2Index(node *n, int Index, int Key) {    //Adding a Node to a specific INDEX of a Linked-List
    node *new = (node *)malloc(sizeof(node));
    new->data = Key;
    if(Index >= 0 && Index < ListLength(n)) {
        for(int a = 0; a < Index-1; a++)
            n = n->next;
        new->next = n->next;
        n->next = new;
    }
    else
        printf("\nError : Index is out of Bounds!");
}

void Add2SortedList(node *n, int Key) {          //Adding a Node to a Sorted Linked-List
    node *new = (node *)malloc(sizeof(node));
    node *prev;
    new->data = Key;
    while(n && n->data < Key) {
        prev = n;
        n = n->next;
    }
    new->next = prev->next;
    prev->next = new; 
}

void DeleteNode(node *n, int Key) {              //Deleting a Node to a given Key in a Linked-list
    node *del, *temp;
    while(n != NULL) {
        if(n->data == Key)
            break;
        temp = n;
        n = n->next;
    }
    temp->next = n->next;
    free(n);
}

int IsSorted(node *n) {                          //Checking if a Linked-List is sorted or not
    int x = n->data;
    n = n->next;
    while(n != NULL) {
        if(n->data < x)
            return 0;
        x = n->data;
        n = n->next;
    }
    return 1;
}

void RemoveDuplicates(node *n) {                 //Remove Duplicate Elements from a Sorted Linked-List
    node *temp = n;
    int x = n->data;
    n = n->next;
    while(n != NULL) {
        if(n->data == x && n->next != NULL) {
            temp->next = n->next;
            free(n);
            break;
        }
        temp = n;
        x = n->data;
        n = n->next;
    }
}