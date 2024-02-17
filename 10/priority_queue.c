/*
PRIORITY QUEUEUEUEEUEUEUEUEUE
*/


#include <stdio.h>
#include <stdlib.h>


typedef
struct Node
{
    int data;
    int priority;
    struct Node *next;
}
NODE;


void enqueue(NODE** front, int value, int priority);
int dequeue(NODE** front);
void display(NODE* front);
int is_empty(NODE* front);

int main()
{
    NODE* front = NULL;

    int choice, value, priority;

    printf("\nPriority Queue Operations Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("0. Exit\n");
    
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                enqueue(&front, value, priority);
                break;
            }
            case 2:
            {
                if (!is_empty(front))
                {
                    value = dequeue(&front);
                    printf("Dequeued element with value %d and priority %d\n", value, priority);
                }
                else
                {
                    printf("Priority Queue is empty. Cannot dequeue.\n");
                }
                break;
            }
            case 3:
            {
                display(front);
                break;
            }
            case 0:
            {
                printf("Exiting the program. Bye!\n");
                return 0;
            }
            default:
            {
                printf("Invalid choice!\n");
            }
        }
    }
}


void enqueue(NODE** front, int value, int priority) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (!new_node)
    {
        printf("Memory allocation failed for node.\n");
        return;
    }

    new_node->data = value;
    new_node->priority = priority;
    new_node->next = NULL;

    if (*front == NULL || priority < (*front)->priority)
    {
        
        new_node->next = *front;
        *front = new_node;
    }
    else
    {
        
        NODE* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    printf("Enqueued: value %d with priority %d\n", value, priority);
}


int dequeue(NODE** front)
{
    if (*front == NULL)
    {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else
    {
        NODE* temp = *front;
        int value = temp->data;
        *front = (*front)->next;
        free(temp);
        return value;
    }
}


void display(NODE* front) {
    if (front == NULL)
    {
        printf("Priority Queue is empty.\n");
    }
    else
    {
        printf("Priority Queue elements: ");
        while (front != NULL)
        {
            printf("(value: %d, priority: %d) ", front->data, front->priority);
            front = front->next;
        }
        printf("\n");
    }
}


int is_empty(NODE* front) {
    return (front == NULL);
}
