#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _bstNode {
    int data;
    struct _bstNode* leftChild;
    struct _bstNode* rightChild;
} bstNode;

typedef struct _bst {
    struct _bstNode* head;
} bst;

bst* makeBST(int val) {
    bstNode* head = (bstNode*)malloc(sizeof(bstNode));
    head->data = val;
    head->leftChild = NULL;
    head->rightChild = NULL;
    bst* BST = (bst*)malloc(sizeof(bst));
    BST->head = head;
    return BST;
}

void insert(bst* BST, int val) {
    bstNode* newNode = (bstNode*)malloc(sizeof(bstNode));
    newNode->data = val;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    bstNode* checkNode = BST->head;
    bstNode* pred = NULL;
    while(checkNode != NULL) {
        pred = checkNode;
        if(checkNode->data > newNode->data) {
            checkNode = checkNode->leftChild;
        }
        else if(checkNode->data < newNode->data) {
            checkNode = checkNode->rightChild;
        }
        else {
            printf("ERROR: CANNOT INSERT DUPLICATES\n");
        }
    }
    if(newNode->data > pred->data) {
        pred->rightChild = newNode;
    }
    else if(newNode->data < pred->data) {
        pred->leftChild = newNode;
    }
}

void inOrderTraversalHelper(bstNode* node) {
    if(node != NULL) {
        inOrderTraversalHelper(node->leftChild);
        printf("%d ", node->data);
        inOrderTraversalHelper(node->rightChild);
    }
}

void preOrderTraversalHelper(bstNode* node) {
    if(node != NULL) {
        printf("%d ", node->data);
        inOrderTraversalHelper(node->leftChild);
        inOrderTraversalHelper(node->rightChild);
    }
}

void postOrderTraversalHelper(bstNode* node) {
    if(node != NULL) {
        inOrderTraversalHelper(node->leftChild);
        inOrderTraversalHelper(node->rightChild);
        printf("%d ", node->data);    
    }
}

void inOrderTraversal(bst* BST) {
    printf("INORDER\n");
    inOrderTraversalHelper(BST->head);
    printf("\n");
}

void preOrderTraversal(bst* BST) {
    printf("PREORDER\n");
    preOrderTraversalHelper(BST->head);
    printf("\n");
}

void postOrderTraversal(bst* BST) {
    printf("POSTORDER\n");
    postOrderTraversalHelper(BST->head);
    printf("\n");
}

#endif