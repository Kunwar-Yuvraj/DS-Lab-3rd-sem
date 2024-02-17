/*
LINEAR QUEUEUEEUEUEUEUEUEUEUE
*/

#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10


typedef struct
{
    int items[MAX_SIZE];
    int front, rear;
} Queue;


void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void display(Queue *q);
int peek(Queue *q);


int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memory allocation for queue failed!\n");
        exit(0);
    }
    q->front = -1;
    q->rear = -1;

    int choice, data;

    printf("\nMAIN MENU :>\n\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            }
            case 2:
            {
                data = dequeue(q);
                if (data != -1)
                {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            }
            case 3:
            {
                display(q);
                break;
            }
            case 4:
            {
                data = peek(q);
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;
            }
            case 0:
            {
                printf("Exiting...\n");
                free(q);
                exit(0);
            }
            default:
            {
                printf("Invalid choice. Please enter a valid option.\n");
            }
        }

    }

    return 0;
}


void enqueue(Queue *q, int data)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = data;
        printf("Enqueued: %d\n", data);
    }
}


int dequeue(Queue *q)
{
    int data = -1;
    if (q->front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        data = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            
            q->front = -1;
            q->rear = -1;
        }
    }
    return data;
}


void display(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}


int peek(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return q->items[q->front];
}
