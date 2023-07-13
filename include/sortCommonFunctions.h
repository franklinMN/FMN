#include<stdio.h>

int arrayLength( int *arr ) {
    int count = 0;
    for(int i=0; *(arr+i)!='\0'; i++)
        count++;
    return count;
}

void displayArrayInt( int *arr ) {
    int count = arrayLength( arr );
    for ( int i=0 ; i<count ; i++ ) {
        printf( "%d  ", *(arr+i) );
    }
    printf( "\n" );
}