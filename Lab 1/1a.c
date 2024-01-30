/*
Create 3 pointers called P1, P2, P3 and an integer variable X where P1
points to P2, P2 points to P3 and P3 points to X. Demonstrate how to
read and retrieve the value of X using P1, P2 and P3
*/


#include <stdio.h>


int main()
{
    int X;
    int *P3 = &X;
    int **P2 = &P3;
    int ***P1 = &P2;

    printf("Enter value of X: ");
    scanf("%d", &X);

    printf("\nValue of 'X' using P3 : %d", *P3);
    printf("\nValue of 'X' using P2 : %d", **P2);
    printf("\nValue of 'X' using P1 : %d\n", ***P1);

    return 0;    
}