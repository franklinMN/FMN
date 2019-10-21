#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
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
  }
  
  else
  {
    temp->next = head;
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
  }
  
  else
  {
    current = head;
  
    for(int i=1 ; i<pos ; i++ )
      current = current->next;
    
       temp->next = current->next; 
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
  }
  
  else
  {
    current = head;
  
    while( current->next != NULL )
       current = current->next;
    
    current->next = temp; 
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
    struct Node *prev = NULL;
    current = head;
  
    while( current->next != NULL )
    {
       prev = current;
       current = current->next;
    }
    
    prev->next = NULL; 
    free( current );
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
    struct Node *prev = NULL;
    current = head;
  
    for(int i=1 ; i<pos ; i++ )
    {
         prev = current;
      current = current->next;
    }
    
       prev->next = current->next;
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

void main()
{
  printf( "\nInserting at First...\n" );
  insertFirst(10);
  display();
  insertFirst(20);
  display();
  insertFirst(30);

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

}
