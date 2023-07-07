#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void insertLeft( struct Node*, int );
void insertRight( struct Node*, int );
int findDepthOfTree( struct Node* );
bool isPerfect( struct Node* );
bool isPerfectBinaryTree( struct Node*, int, int );
struct Node *createNode( int value );

int main() {
    printf( "Creating the root node.\n" );
    struct Node *root = createNode(1);
    printf("Inserting nodes to tree...\n");
    insertLeft( root, 12 );
    insertRight( root, 9 );
    // insertLeft( root->left, 5 );
    // insertRight( root->left, 6 );
    insertLeft( root->right, 5 );
    insertRight( root->right, 6 );
    // insertLeft( root->left->left, 5 );
    // insertRight( root->left->left, 10 );
    // insertLeft( root->left->right, 5 );
    // insertRight( root->left->right, 10 );
    // insertLeft( root->right->left, 5 );
    // insertRight( root->right->left, 10 );
    // insertLeft( root->right->right, 5 );
    // insertRight( root->right->right, 10 );
    bool result = isPerfect(root);
    if( result ){
        printf("\nThe TREE is a PERFECT BINARY TREE.\n");
    }else {
        printf("\nThe TREE is a NOT a Perfect Binary Tree.\n");
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

int findDepthOfTree( struct Node *root ) {
    int d=0;
    while( root != NULL ){
        d++;
        root = root->left ;
    }
    return d;
}

bool isPerfect( struct Node *root ) {
    int depth = findDepthOfTree(root);
    printf("Depth : %d\n", depth);
    return isPerfectBinaryTree( root, depth, 0 );
}

bool isPerfectBinaryTree( struct Node *currentNode, int depth, int height ) {
    if( currentNode == NULL )
        return true;
    if( currentNode->left == NULL && currentNode->right == NULL )
        return (depth == height+1);
    if( currentNode->left == NULL || currentNode->right == NULL )
        return false;
    return isPerfectBinaryTree( currentNode->left, depth, height+1 ) && isPerfectBinaryTree(currentNode->right, depth, height+1);
}