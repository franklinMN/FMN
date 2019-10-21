#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head = NULL;
struct Node *current = NULL; 

//_____________________________________________________________________________________

void insertFirst( int n )
{
  struct Node *temp = ( struct Node* )malloc( sizeof( struct Node ) );
         temp->data = n;
         

  if( head == NULL )
  {
           head = temp;
     temp->next = NULL;
     temp->prev = NULL;
  }
  
  else
  {
    temp->next = head;
    head->prev = temp;
          head = temp;
  }
}


//_______________________________________________________________________________________

void insertMiddle( int n , int pos)
{
  struct Node *temp = ( struct Node* )malloc( sizeof( struct Node ) );
         temp->data = n;

  if( head == NULL )
  {
           head = temp;
     temp->next = NULL;
     temp->prev = NULL;
  }
  
  else
  {
    current = head;
  
    for(int i=1 ; i<pos ; i++ )
      current = current->next;
    
       temp->next = current->next; 
       temp->prev = current;
    current->next = temp;
  }
}


//_______________________________________________________________________________________

void insertLast( int n )
{
  struct Node *temp = ( struct Node* )malloc( sizeof( struct Node ) );
         temp->data = n;

  if( head == NULL )
  {
           head = temp;
     temp->next = NULL;
     temp->prev = NULL;
  }
  
  else
  {
    current = head;
  
    while( current->next != NULL )
       current = current->next;
    
    current->next = temp; 
       temp->prev = current;
  }
}

//________________________________________________________________________

void deleteBegin()
{
  if( head == NULL )
  {
     printf( "list is empty....\n" );
     printf( "insert or quit...\n" );
  }
  
  else
  {
       current = head;
          head = head->next;
    head->prev = NULL;
    
    free( current );
  }
}

//_______________________________________________________________________

void deleteLast()
{
  if( head == NULL )
  {
     printf( "list is empty....\n" );
     printf( "insert or quit...\n" );
  }
  
  else
  {
    struct Node *backNode = NULL;
    current = head;
  
    while( current->next != NULL )
    {
      //  prev = current;
       current = current->next;
    }
    
    backNode = current->prev; 
    free( current );
    backNode->next = NULL;
    
  }
}


//_______________________________________________________________________

void deleteMiddle(int pos)
{
  if( head == NULL )
  {
     printf( "list is empty....\n" );
     printf( "insert or quit...\n" ); 
  }
  
  else
  {
    struct Node *linkNode = NULL;
    current = head;
  
    for(int i=1 ; i<pos ; i++ )
    {
       //  prev = current;
      current = current->next;
    }
    
             linkNode = current->prev;
       linkNode->next = current->next;
             linkNode = current->next;
       linkNode->prev = current->prev;

       free( current );
  }
}

//_________________________________________________________________________

void display()
{
 // struct Node *travel ;

  current = head;

  while( current != NULL )
  {
     printf( "%d  ", current->data );
    // printf( "\n" );
     current = current->next;
  }
  printf( "\n" );
}

void reversePrint()
{
  current = head;
  
  while( current->next != NULL )
    current = current->next;

  while( current != NULL )
  {
     printf( "%d  ", current->data );
     current = current->prev;
  }
  printf( "\n" );
}


void main()
{
  printf( "\nInserting at First...\n" );
  insertFirst(10);
  display();
  insertFirst(20);
  display();
  insertFirst(30);
  display();

  printf( "\nInserting at Last...\n" );
  insertLast(40);
  display();
  insertLast(50);
  display();

  printf( "\nInserting at Middle ...\n" );
  insertMiddle(60,3);
  display();

  printf( "\nDeleting at Beginning...\n" );
  deleteBegin();
  display();

  printf( "\nDeleting at End...\n" );
  deleteLast();
  display();

  printf( "\nDeleting at Middle...\n" );
  deleteMiddle(3);
  display();

  printf( "Printing the elements in reverse order...\n" );
  reversePrint();

}
