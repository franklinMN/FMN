#include<stdio.h>

int main() {
    int array[] = { 10, 1, 15, -10, -1 };

    int size = sizeof(array) / sizeof(array[0]);

    for ( int i=0 ; i<size ; i++ ) {
        printf( "Value[%d] is %d\n", i , array[i] );
    }

    printf( "Sorting Process...\n" );

    for( int i=0 ; i<size ; i++ ){
        int minValue;
        for( int j=i+1 ; j<size ; j++ ) {
            if ( array[i]>array[j] ) {
                minValue = array[j];
                array[j] = array[i];
                array[i] = minValue;
            }
        }
    }

    printf( "After Sorting Process...\n" );

    for ( int i=0 ; i<size ; i++ ) {
        printf( "Value[%d] is %d\n", i , array[i] );
    }
}