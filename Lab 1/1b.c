/*
Crate a pointer to an integer array, Read and display the contents using
pointer and also display the contents in reverse order using pointer.
*/


#include <stdio.h>
#include <stdlib.h>


int i;


void read(int *, int);
void display(int *, int);
void display_reverse(int *, int);


int main()
{
    int n;
    printf("Number of elements you want to enter: ");
    scanf("%d", &n);

    int arr[n], *ptr;
    ptr = arr;

    read(ptr, n);
    display(arr, n);
    display_reverse(arr, n);

    return 0;
}


void read(int *ptr, int n)
{
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }
}


void display(int *ptr, int n)
{
    printf("Array:\n");
    for (i=0; i<n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    printf("\n");
}


void display_reverse(int *ptr, int n)
{
    printf("Array in reverse:\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d\t", *(ptr + i));
    }
    printf("\n");
}