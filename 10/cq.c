/*
CIRCULAR QUEUEUEUEUEUEUEUEUEUEUE
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CQ;


void enqueue(CQ *cq, int data);
int dequeue(CQ *cq);
void display(CQ *cq);
int peek(CQ *cq);

int main()
{
    CQ *cq = (CQ *)malloc(sizeof(CQ));
    if (cq == NULL)
    {
        printf("Memory allocation for circular queue failed!\n");
        exit(0);
    }
    cq->front = -1;
    cq->rear = -1;

    int choice, data;

    printf("\nMAIN MENU :>\n\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("0. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(cq, data);
                break;
            }
            case 2:
            {
                data = dequeue(cq);
                if (data != -1)
                {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            }
            case 3:
            {
                display(cq);
                break;
            }
            case 4:
            {
                data = peek(cq);
                if (data != -1)
                {
                    printf("Front element: %d\n", data);
                }
                break;
            }
            case 0:
            {
                printf("Exiting...\n");
                free(cq);
                return 0;
            }
            default:
            {
                printf("Invalid choice!\n");
            }
        }
    }
}


void enqueue(CQ *cq, int data) {
    if ((cq->rear + 1) % MAX_SIZE == cq->front)
    {
        printf("Queue overflow!\n");
    }
    else
    {
        if (cq->front == -1)
        {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % MAX_SIZE;
        cq->items[cq->rear] = data;
        printf("Enqueued: %d\n", data);
    }
}


int dequeue(CQ *cq) {
    int data = -1;
    if (cq->front == -1)
    {
        printf("Queue underflow!\n");
    }
    else
    {
        data = cq->items[cq->front];
        if (cq->front == cq->rear)
        {
            
            cq->front = -1;
            cq->rear = -1;
        }
        else
        {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
    }
    return data;
}


void display(CQ *cq)
{
    if (cq->front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Circular Queue elements: ");
        int i = cq->front;
        do
        {
            printf("%d ", cq->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        while (i != (cq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}


int peek(CQ *cq)
{
    if (cq->front == -1)
    {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    else
    {
        return cq->items[cq->front];
    }
}
