#include<stdio.h>

int strcmpExample( char s1[], char s2[] ) {

    int result = 0;
    for ( int i=0 ; s1[i]!='\0' ; i++ ) {
        if ( s1[i] != s2[i] ) {
            return ++result;
            //break;
        }
    }
    return result;
}

void main () {
    char str1[] = "Franklin";
    char str2[] = "Franklin";
    char str3[] = "Maria";

   // printf( "\n%d\n", strcmpExample( str1, str3 ) );

    if (!strcmpExample( str1, str3 )) {
        printf("The strings are equal.\n");
    }else {
        printf("The string is not equal\n");
    }
}