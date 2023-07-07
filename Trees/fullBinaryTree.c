#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *left, *right; // left and right child pointers of the node
};

void insertLeft( struct Node*, int );
void insertRight( struct Node*, int );
struct Node *createNode( int value );
bool isFullBinaryTree( struct Node* );

int main() {
    printf( "Creating the root node.\n" );
    struct Node *root = createNode(1);
    printf("Inserting nodes to tree...\n");
    insertLeft( root, 12 );
    insertRight( root, 9 );
    insertLeft( root->left, 5 );
    insertRight( root->left, 6 );
    insertLeft( root->left->left, 5 );
    insertRight( root->left->left, 10 );
    bool result = isFullBinaryTree(root);
    if( result ){
        printf("\nThe TREE is a FULL BINARY TREE.\n");
    }else {
        printf("\nThe TREE is a NOT a Full Binary Tree.\n");
    }
    return 0;
}

void insertLeft( struct Node *currentNode, int value ) {
    currentNode->left = createNode(value);
}

void insertRight( struct Node *currentNode, int value ) {
    currentNode->right = createNode(value);
}

struct Node *createNode( int value ){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

bool isFullBinaryTree( struct Node *currentNode ) {
    if ( currentNode == NULL )
        return true;
    if ( currentNode->left==NULL && currentNode->right==NULL )
        return true;
    if ( (currentNode->left!=NULL) && (currentNode->right!=NULL) )
        return( isFullBinaryTree(currentNode->left) && isFullBinaryTree(currentNode->right) );
        
    return false;
}