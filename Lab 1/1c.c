/*
Create a pointer to an integer array and pass this as parameter to a
function called Reverse which reverses the array contents using pointer.
Write different functions called Read (P) to read the array elements
using pointer P and Display (P) to display the array contents using P
before and after reverse.
*/


#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE 10
int i;


void Read(int *P, int size)
{
    printf("Enter elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", (P + i));
    }
}


void Reverse(int *P, int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int temp = *(P + start);
        *(P + start) = *(P + end);
        *(P + end) = temp;
        start++;
        end--;
    }
}


void Display(int *P, int size)
{
    printf("Array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", *(P + i));
    }
    printf("\n");
}


int main()
{
    int size;
    printf("Size of array: ");
    scanf("%d", &size);
    int array[size], *P;
    P = array;

    Read(P, size);

    printf("\nBefore reverse:\n");
    Display(P, size);

    Reverse(P, size);
    
    printf("\nAfter reverse:\n");
    Display(P, size);

    return 0;
}