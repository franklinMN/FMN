#include<stdio.h>

int strlenExample( char arr[] ) {
    printf( "\n%s\n", arr );

    int lenght;
    for (lenght=0 ;arr[lenght]!= '\0' ; ++lenght) {}

    return lenght;
}

int main () {
    char array[] = "FranklinMarianayagam";
    int length = strlenExample( array );
    printf( "Lenght of the given string %s is %d.\n", array, length );
    return 0;
}