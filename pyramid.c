#include <stdio.h>

void main()
{
  int i=0 , j=0 , n=5;
  
  for( i=1 ; i<=n ; i++ )
  {

    for( int c=i ; c<=n ; c=c+1 )
    {
      printf( "  " );
    }

    for( j=1 ; j<=i ; j++ )
    { 
      printf( "  * " );
    }
    printf( "\n" );
  }
   
 // printf("\n");   

  for( i=n-1 ; i>=1 ; i-- )
  {

    for( int c=i ; c<=n ; c=c+1 )
    {
      printf( "  " );
    }

    for( j=i ; j>=1 ; j-- )
    { 
      printf( "  * " );
    }
    printf( "\n" );
  }
}
