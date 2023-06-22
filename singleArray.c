#include<stdio.h>

void displayArray( int arr[], int s ) {
    for ( int i=0 ; i<s ; i++ ) {
        printf( "Value[%d] is %d\n", i , arr[i] );
    }
}

int main() {
    int array[] = { 10, 1, 15, -10, -1 };

    int size = sizeof(array) / sizeof(array[0]);

    displayArray( array, size );

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

    displayArray( array, size );
}