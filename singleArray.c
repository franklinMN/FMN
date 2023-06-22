#include<stdio.h>

int main() {
    int array[] = { 10, 1, 15, -10, -1 };

    int size = sizeof(array) / sizeof(array[0]);

    for ( int i=0 ; i<size ; i++ ) {
        printf( "Value[%d] is %d", i , array[i] )
    }
}