#include<stdio.h>

int main() {
    FILE *ptr;
    ptr = fopen("test.txt", "w");
    fprintf(ptr, "Franklin Maria Nayagam S");
    fclose(ptr);
    return 0;
}