#include<stdio.h>
#include<conio.h>
char* strlwrExample( char arr[] );

int main() {
    char array[] = "Franklin Maria Nayagam S";
    char* resultArray = strlwrExample( array );
    printf("Result array: %s\n",resultArray);
    getch();
}

char* strlwrExample( char arr[] ) {
   // int num;
    for( int i=0 ; arr[i] != '\0' ; i++ ) {
        if( arr[i]>='A' && arr[i]<='Z' ) {
            //printf("%d   ", (int)arr[i]);
            arr[i] = arr[i] + 32;
        }
    }
    return (arr);
}