/*
Create a pointer to two dimensional array of integers. Write functions
Read (P) and Display (P) to read and display the contents using pointer.
*/


#include <stdio.h>
#include <stdlib.h>


int i, j;


void Read(int *, int, int);
void Display(int *, int, int);


int main()
{
    int row, col;
    printf("Enter rows and columns: ");
    scanf("%d %d", &row, &col);

    int array[row][col], *P;
    P = array;

    Read(P, row, col);
    Display(P, row, col);

    return 0;
}



void Read(int *P, int row, int col)
{
    printf("Enter elements:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", (P + i * col + j));
        }
    }
}


void Display(int *P, int row, int col)
{
    printf("Array:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", *(P + i * col + j));
        }
        printf("\n");
    }
}