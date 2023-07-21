#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int);
void insertEnd(Node*, int);
void insertBegin(Node*, int);
void insertAfter(Node*, int, int);
void displayList(Node*);

Node  *head = NULL;

int main(){
    insertEnd(head, 5);         displayList(head);
    insertEnd(head, 5);         displayList(head);
    insertBegin(head, 10);      displayList(head);
    insertBegin(head, 10);      displayList(head);
    insertAfter(head, 7, 4);    displayList(head);
    insertAfter(head, 1, 4);    displayList(head);
    printf("\n----------------------------------\n");

}

Node *createNode( int item ){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd( Node* currentNode, int item ){
    Node *newNode = createNode(item);
    
    if( head == NULL )
        head = newNode;
    else {
        Node *temp = currentNode;
        while(temp -> next!=NULL) {
            temp = temp->next;
        }
        // Insert the new node at last position of linked list
        currentNode->next = newNode;
        newNode->prev=currentNode;
    }
}

void insertBegin(Node* currentNode, int item){
    Node *newNode = createNode(item);

    if( head == NULL )
        head = newNode;
    else {
        // Update head to point to newly created node.
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAfter(Node* currentNode, int item, int position){
    Node *newNode = createNode(item);

    if( head == NULL )
        head = newNode;
    else {
        Node *temp = currentNode;
        for ( int i = 0 ; i < position-1 ; i++ ) {
            temp = temp->next;
        }
        // If we have reached end of current LinkedList then simply add it as a normal element in Linked
        if(!temp || !temp->next)
            insertEnd(temp, item );
        else{
            // Create New Node and update pointers accordingly
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            }
    }
}

void displayList(Node* currentNode) {
    Node *temp = currentNode;
    printf("\n----------------------------------\n");
    printf("LinkedList: ");
    while( temp != NULL ){
        printf("%d   ", temp->data);
        temp = temp->next;
    }
   // printf("\n----------------------------------\n");
}