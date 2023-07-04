#include<stdio.h>
#include<stdlib.h>
// Tree Node Structure...........................................................
struct Node {
    int data;
    struct Node *left, *right; // left and right child pointers of the node
};

//.....Function declarations starts...............................................
void inOrderTraversal( struct Node* );
void preOrderTraversal( struct Node* );
void postOrderTraversal( struct Node* );
void insertLeft( struct Node*, int );
void insertRight( struct Node*, int );
struct Node *createNode( int value );
//.....Function declarations ends.................................................

//....main function starts........................................................
int main() {
    printf( "Creating the root node.\n" );
    struct Node *root = createNode(1);
    printf("Inserting nodes to tree...\n");
    insertLeft( root, 12 );
    insertRight( root, 9 );
    insertLeft( root->left, 5 );
    insertRight( root->left, 6 );
    //printf("Insertion completed...\n");

    printf( "\nInorder traversal : \n" );
    inOrderTraversal( root );

    printf( "\nInorder traversal : \n" );
    preOrderTraversal( root );
    
    printf( "\nInorder traversal : \n" );
    postOrderTraversal( root );
    return 0;
}
//....main function ends........................................................

struct Node *createNode( int value ){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insertLeft( struct Node *currentNode, int value ) {
    currentNode->left = createNode(value);
}

void insertRight( struct Node *currentNode, int value ) {
    currentNode->right = createNode(value);
}

void inOrderTraversal( struct Node *root ) {
    if (root==NULL) {
        return;
    }else{
        inOrderTraversal(root->left);
        printf(" %d -", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal( struct Node *root ){
    if ( root==NULL ) {
        return;
    }else {
        printf(" %d -", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal( struct Node *root ){
    if ( root==NULL ) {
        return;
    }else {
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
        printf(" %d -", root->data);
    }
}