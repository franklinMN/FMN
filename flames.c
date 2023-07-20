#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void findFlames( char[], char[], char[] );
int rearrangeString( int , char *, int  );
void lowerCasing( char *, int );

int main() {

    char flames[] = "FLAMES";
    char nameOne[50];
    char nameTwo[50];
    int n1Lenght, n2Lenght;

    printf( "Enter the first person full Name : " );
    gets( nameOne );
    printf( "Enter the Second person full Name : " );
    gets( nameTwo );

    n1Lenght = strlen(nameOne);

    n2Lenght = strlen(nameTwo);

    lowerCasing(nameOne, n1Lenght);

    lowerCasing(nameTwo, n2Lenght);

    findFlames( flames, nameOne, nameTwo );

    return 0;
}

void findFlames( char flames[], char n1[], char n2[] ) {

    // PART 1 : This for loop is used to cancel the same letters.....
    for( int i=0 ; n1[i]!='\0' ; i++) {
        //printf( "%c ", n1[i] );
        for( int j=0 ; n2[j]!='\0' ; j++ ) {
            if ( n1[i] == n2[j] ) {
                n1[i] = n2[j] = '0';
                break;
            }
        }
    }
    printf( "%s     ", n1 );
    printf( "%s \n", n2 );
    //PART 1 ENDS......

    // PART 2 : This code is to calculate the total lenght of the remaining letters from the two string....
    int count = 0;
    for ( int i=0 ; n1[i]!='\0' ; i++ ) {
        if( n1[i] != '0' )
            count++;
    }
    printf( "Total count is : %d\n", count );
    for ( int i=0 ; n2[i]!='\0' ; i++ ) {
        if( n2[i] != '0' )
            count++;
    }
    printf( "Total count is : %d\n", count );
    //PART 2 ENDS....

    //PART 3 : Calculate flames based on the total length "count"
    int currentFLen = 5;
    while( currentFLen!=0 ) {
        int length = 0;
        int j=0;
        for ( j=0 ; length<count-1 ; j++, length++ ) {
            if( j == currentFLen )
                j = -1;
        }
        currentFLen = rearrangeString( j, &flames[0], currentFLen );
    }
    //PART 3 ENDS....
    printf("\n-----------------\n");
    //printf("%s", flames);

    switch (flames[0]) {
        case 'F': puts("FRIENDS"); break;
        case 'L': puts("LOVE"); break;
        case 'A': puts("AFFECTION"); break;
        case 'M': puts("MARRIAGE"); break;
        case 'E': puts("ENEMY"); break;
        case 'S': puts("SISTERS, BROTHERS"); break;
    }
    printf("-----------------\n");

}

int rearrangeString( int position, char *ptr, int cfl ){
    char *temp = malloc(cfl*sizeof(char));
    strcpy( temp, ptr );
    int i;
    for ( i=0 ; i<cfl ; i++ ) {
        if ( position == cfl )
            position = -1;
        *(ptr + i) = *(temp + (position + 1) );
        position++;   
    }
    *(ptr+i) = '\0';
    printf("%s\n", ptr);
    free(temp);
    return cfl - 1;
}

void lowerCasing( char *ptr, int lenght ) {
    char *temp = malloc(lenght*sizeof(char));
    strcpy( temp, ptr );
    int i=0;
    while( *(temp+i) ) {
        *(ptr+i) = (char)tolower( *(temp+i) );
        i++;
    }
    free(temp);
}