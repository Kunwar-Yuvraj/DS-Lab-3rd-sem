/*
Develop a menu driven program to implement Stack with dynamic memory allocation (Linked List)
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
} 
NODE;


typedef struct
{
    int size;
    int max_size;
    NODE *top;
} 
STACK;


NODE * create_node(int);
STACK * create_stack(int);
void display(STACK *);
void push_stack(STACK *, int);
int pop_stack(STACK *);
int peek_stack(STACK *);


int main()
{
    int max_size;
    printf("Enter max size of stack : ");
    scanf("%d", &max_size);
    
    STACK *stack = create_stack(max_size);

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
                display(stack);
                break;
            }
            case 2:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                push_stack(stack, data);
                break;
            }
            case 3:
            {
                int pop = pop_stack(stack);
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
                int peek = peek_stack(stack);
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

    free(stack);

    return 0;
}


NODE * create_node(int data)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    if (new == NULL)
    {
        printf("Memory allocation failed for node!");
        return NULL;
    }
    new->data = data;
    new->link = NULL;

    return new;
}


STACK * create_stack(int max_size)
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    if (stack == NULL)
    {
        printf("Memory allocation failed for stack!");
        return NULL;
    }
    stack->top = create_node(0);
    stack->size = 0;
    stack->max_size = max_size;

    return stack;
}


void display(STACK *stack)
{
    if (stack->top->link == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack:\n");
    NODE *curr = stack->top->link;
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->link;
    }
    printf("\n");
}


void push_stack(STACK *stack, int data)
{
    if (stack->size >= stack->max_size)
    {
        printf("Stack overflow, can't push!\n");
        return;
    }
    NODE *new = create_node(data);
    if (stack->top->link == NULL)
    {
        stack->top->link = new;
    }
    else
    {
        new->link = stack->top->link;
        stack->top->link = new;
    }
    stack->size += 1;
    printf("Pushed!\n");
}


int pop_stack(STACK *stack)
{
    if (stack->top->link == NULL)
    {
        return -1;
    }
    NODE * curr = stack->top->link;
    int pop = curr->data;
    stack->top->link = curr->link;
    free(curr);
    stack->size -= 1;

    return pop;
}


int peek_stack(STACK *stack)
{
    if (stack->top->link == NULL)
    {
        return -1;
    }
    return stack->top->link->data;
}