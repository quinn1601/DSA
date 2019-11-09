#include "binary_search_tree.h"

int main() {
    bst* BST = makeBST(5);
    insert(BST, 3);
    insert(BST, 7);
    insert(BST, 2);
    insert(BST, 9);
    insert(BST, 8);
	insert(BST, 1);
	insert(BST, 4);
	insert(BST, 6);
	insert(BST, 0);
	inOrderTraversal(BST);
    preOrderTraversal(BST);
    postOrderTraversal(BST);
    return 0;
}