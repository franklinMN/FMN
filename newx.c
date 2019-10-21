#include <stdio.h>

void main()
{
  int i=0 , j=0 , n=5 ;
  
   for( i=n ; i>=1 ; i-- )
  {

    for( int c=i ; c<=n ; c=c+1 )
    {
      printf( "  " );
    }

    for( j=i ; j>=1 ; j-- )
    { 
       
      if( j==i || j==1 )
         printf( "  🔥️" );
      else
         printf("    ");
    }
    printf( "\n" );
  }
  
  for( i=2 ; i<=n ; i++ )
  {

    for( int c=i ; c<=n ; c=c+1 )
    {
      printf( "  " );
    }

    for( j=1 ; j<=i ; j++ )
    { 
      if( j==1 || j==i )
        printf( "  🔥️" );
      else
        printf( "    " );
    }
    printf( "\n" );
  }
   
 // printf("\n");   
}

 
