/*
Develop a menu driven program to implement Stack with static memory allocation (array)
*/


#include <stdio.h>


#define MAX_SIZE 10


void display(int [], int);
void push_stack(int [], int *, int);
int pop_stack(int [], int *);
int peek_stack(int [], int);


int main()
{
    int stack[MAX_SIZE];
    int top = -1;

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
                display(stack, top);
                break;
            }
            case 2:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                push_stack(stack, &top, data);
                break;
            }
            case 3:
            {
                int pop = pop_stack(stack, &top);
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
                int peek = peek_stack(stack, top);
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
            case 0:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid choice!\n");
            }
        }
    } while (choice != 0);
    
    return 0;
}


void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    int i;
    printf("Stack :\n");
    for (i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}


void push_stack(int stack[], int *top, int data)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack overflow, can't push!\n");
        return;
    }
    stack[++(*top)] = data;
    printf("Pushed!\n");
}


int pop_stack(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow, can't pop!\n");
        return -1;
    }
   return stack[(*top)--];
}


int peek_stack(int stack[], int top)
{
    if (top == -1)
    {
        return -1;
    }
   return stack[top];
}
