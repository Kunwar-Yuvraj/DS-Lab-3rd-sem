/*
Define a structure called Student with the members: Name, Reg_no, marks in
3 tests and average_ marks.

Develop a menu driven program to perform the following by writing separate
function for each operation: 
a) read information of N students 
b) display student's information 
c) to calculate the average of best two test marks of
each student.

Note: Allocate memory dynamically and illustrate the use of pointer to an
array of structure. 
*/


#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE 25


int i, j;


typedef struct Student
{
    char Name[25];
    int Reg_no;
    int marks[3];
    float average_marks;
} 
STUDENT;


void read(STUDENT *, int *);
void display(STUDENT *, int *);
void calc_avg(STUDENT *, int *);


int main()
{
    int N = 0;

    STUDENT *students = (STUDENT *)malloc(MAX_SIZE * sizeof(STUDENT));
    if (students == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("\nMAIN MENU :> \n\n");
    printf("1. Read\n");
    printf("2. Display\n");
    printf("3. Calculate Average\n");
    printf("0. Exit\n");

    int choice;
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                read(students, &N);
                break;
            }
            case 2:
            {

                display(students, &N);
                break;
            }
            case 3:
            {
                calc_avg(students, &N);
                break;
            }
            case 0:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != 0);

    free(students);

    return 0;
}


void read(STUDENT *students, int *N)
{
    printf("Name: ");
    scanf("%s", (students + *N)->Name);
    printf("Registration Number: ");
    scanf("%d", &(students + *N)->Reg_no);
    printf("Marks in 3 tests:\n");
    for (j = 0; j < 3; j++)
    {
        scanf("%d", &(students + *N)->marks[j]);
    }
    printf("\nDetails Added!\n");
    *N += 1;
}



void display(STUDENT *students, int *N)
{
    printf("\nTotal students : %d\n", *N);
    if (*N > 0)
    {
        for (i = 0; i < *N; i++)
        {
            printf("\nDetails for student %d:\n", i+1);
            printf("Name: %s\n", (students + i)->Name);
            printf("Registration Number: %d\n", (students + i)->Reg_no);
            printf("Marks in 3 tests: %d %d %d\n", (students + i)->marks[0],(students + i)->marks[1], (students + i)->marks[2]);
            printf("Average Marks: %.2f\n", (students + i)->average_marks);
        }
    }
    else
    {
        printf("Press 1 to input student information!\n");
    }
}


void calc_avg(STUDENT *students, int *N)
{
    if (*N > 0)
    {
        for (i = 0; i < *N; i++)
        {
            int sum = 0;
            int min = (students + i)->marks[0];

            for (j = 0; j < 3; j++)
            {
                if (min > ((students + i)->marks[j]))
                {
                    min = (students + i)->marks[j];
                }
                sum += (students + i)->marks[j];
            }
            (students + i)->average_marks = (float)(sum - min)/2.0;
        }
        printf("Averages calculated!\n");
    }
    else
    {
        printf("Press 1 to add student information!\n");
    }
}