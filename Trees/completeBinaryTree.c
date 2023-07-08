#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

struct Node *createNode( int );
int totalElements( struct Node* );
bool completeBinaryTree( struct Node*, int, int );

struct Node {
    int data;
    struct Node *left;
    struct Node* right;
};

int main() {
    struct Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(10);
    int totalElement = totalElements( root );
    //printf("\n---------------------------------------------------\n");
    printf("\nTotal elements in the tree are: %d\n",totalElement);
    //printf("\n---------------------------------------------------\n");
    int index = 0;
    if( completeBinaryTree( root, index, totalElement ) )
        printf("\nThe Tree is COMPLETE binary tree...\n\n");
    else
        printf("\nNOT a Complete Binary Tree...\n\n");
    getch();
    return 0;

}

struct Node *createNode( int value ) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int totalElements( struct Node *root ) {
    int count=0;
    if(root==NULL)
        return 0;
    else
        return ( 1 + totalElements(root->left) + totalElements(root->right) );
}

bool completeBinaryTree( struct Node *currentNode, int index, int totalElements ) {
    if( currentNode == NULL )
        return true;   /* empty node */
    if( index >= totalElements )
        return false;
    
    return completeBinaryTree( currentNode->left, 2*index+1, totalElements ) && completeBinaryTree( currentNode->right, 2*index+2, totalElements );
}
