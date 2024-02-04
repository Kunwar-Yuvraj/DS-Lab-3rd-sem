/*
Develop a menu driven program to implement Stack with static memory allocation (array)
*/


#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 3


void display(int [], int);
void push_stack(int [], int *, int);
int pop_stack(int [], int *);
int peek_stack(int [], int);


int main()
{
    int stack[MAX_SIZE];
    int size = 0;

    printf("\nMAIN MENU :> \n\n");
    printf("1. Display\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Peek\n");
    printf("0. Exit\n");

    int choice;
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                display(stack, size);
            }
            case 2:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                push_stack(stack, &size, data);
                break;
            }
            case 3:
            {
                int pop = pop_stack(stack, &size);
                if (pop == -1)
                {
                    printf("Stack underflow, can't pop!\n");
                }
                else
                {
                    printf("Element popped : %d\n", pop);
                }
                break;
            }
            case 4:
            {
                int peek = peek_stack(stack, size);
                if (peek != -1)
                {
                    printf("Top of the stack : %d\n", peek);
                }
                else
                {
                    printf("Stack is empty!\n");
                }
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}


void display(int stack[], int size)
{
    if (size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}


void push_stack(int stack[], int *size, int data)
{
    if (*size >= MAX_SIZE)
    {
        printf("Stack overflow, can't push!\n");
        return;
    }
    stack[(*size)++] = data;
    printf("Pushed!\n");
}


int pop_stack(int stack[], int *size)
{
    if (*size == 0)
    {
        printf("Stack underflow, can't pop!\n");
        return -1;
    }
    int pop = stack[--(*size)];
    return pop;
}


int peek_stack(int stack[], int size)
{
    if (size == 0)
    {
        return -1;
    }
   return stack[size-1];
   return 1;
}
