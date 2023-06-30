#include<stdio.h>
#include<conio.h>
char* struprExample( char arr[] );

int main() {
    char array[] = "Franklin Maria Nayagam S";
    char* resultArray = struprExample( array );
    printf("Result array: %s\n",resultArray);
    getch();
}

char* struprExample( char arr[] ) {
   // int num;
    for( int i=0 ; arr[i] != '\0' ; i++ ) {
        if( arr[i]>='a' && arr[i]<='z' ) {
           // printf("%d   ", (int)arr[i]);
            arr[i] = arr[i] - 32;
        }
    }
    return (arr);
}