#include<stdio.h>

// int arrayLength( int arr[] ) {
//     int count = 0;
//     for(int i=0; arr[i]!='\0'; i++)
//         count++;
//     return count;
// }

void displayArrayInt( int arr[], int len ) {
    //int count = arrayLength( arr );
    for ( int i=0 ; i<len ; i++ ) {
        printf( "%d  ", arr[i] );
    }
    printf( "\n" );
}

void swap( int *data1, int *data2 ) {
    int temp;
    temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

void selectionSortASC( int *array, int len ) {
    int *minValue;
    printf( "\nSelection sort process...\n" );
    for( int step = 0 ; step<len-1 ; step++ ) {
        minValue =  array+step ;
        for( int j = step+1 ; j<len; j++ ) {
            if ( *(array+j) < *minValue )
                minValue = array+j;
        }
        swap(array+step, minValue);
        displayArrayInt( array, len );
    }
}

void selectionSortDSC( int *array, int len ) {
    int *maxValue;
    printf( "\nSelection sort process...\n" );
    for( int step = 0 ; step<len-1 ; step++ ) {
        maxValue =  array+step ;
        for( int j = step+1 ; j<len; j++ ) {
            if ( *(array+j) > *maxValue )
                maxValue = array+j;
        }
        swap(array+step, maxValue);
        displayArrayInt( array, len );
    }
}

void bubbleSortDSC( int *array, int len ) {
    //int *minValue;
    printf( "\nBubble sort process...\n" );
    for( int i=0 ; i<len-1 ; i++ ){
        //minValue = array+i;
        for( int j=i+1 ; j<len ; j++ ) {
            if( *(array+i) < *(array+j) ) {
                swap( array+i , array+j );
            }
        }
        displayArrayInt( array, len );
    }
}

void bubbleSortASC( int *array, int len ) {
    //int *minValue;
    printf( "\nBubble sort process...\n" );
    for( int i=0 ; i<len-1 ; i++ ){
        //minValue = array+i;
        for( int j=i+1 ; j<len ; j++ ) {
            if( *(array+i) > *(array+j) ) {
                swap( array+i , array+j );
            }
        }
        displayArrayInt( array, len );
    }
}

void insertionSortASC ( int *array, int len ) {
    for ( int step = 1 ; step<len ; step++ ) {
        int key = *(array+step);
        int j = step - 1;
        while ( j >= 0 && key<*(array + j)) {
            *(array+(j+1)) = *(array+j);
            --j;
        }
        *(array+(j+1)) = key;
    }
}