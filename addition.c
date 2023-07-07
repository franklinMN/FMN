#include<stdio.h>
#include<conio.h>

int main() {
    int num1, num2, sum;
    printf("Enter First element: ");
    scanf("%d", &num1);
    printf("Enter Second element: ");
    scanf("%d", &num2);
    sum = num1 + num2;
    printf("Sum of two values : %d", sum);
    getch();
    return 0;
}