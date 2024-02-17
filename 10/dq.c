/*
DOUBLE ENDED QQQQQQQQUEUEUEUEUEUEUE
*/


#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10


typedef
struct
{
    int items[MAX_SIZE];
    int front, rear;
}
DQ;


void enqueue_front(DQ *dq, int data);
void enqueue_rear(DQ *dq, int data);
int dequeue_front(DQ *dq);
int dequeue_rear(DQ *dq);
void display(DQ *dq);
int peek_front(DQ *dq);
int peek_rear(DQ *dq);

int main()
{
    DQ *dq = (DQ *)malloc(sizeof(DQ));
    if (dq == NULL)
    {
        printf("Memory allocation for DQ failed!\n");
        return 0;
    }
    dq->front = -1;
    dq->rear = -1;

    int choice, data;

    printf("\nMAIN MENU :>\n\n");
    printf("1. Enqueue Front\n");
    printf("2. Enqueue Rear\n");
    printf("3. Dequeue Front\n");
    printf("4. Dequeue Rear\n");
    printf("5. Display\n");
    printf("6. Peek Front\n");
    printf("7. Peek Rear\n");
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
                enqueue_front(dq, data);
                break;
            }
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue_rear(dq, data);
                break;
            case 3:
            {
                data = dequeue_front(dq);
                if (data != -1)
                {
                    printf("Dequeued element from the front: %d\n", data);
                }
                break;
            }
            case 4:
            {
                data = dequeue_rear(dq);
                if (data != -1)
                {
                    printf("Dequeued element from the rear: %d\n", data);
                }
                break;
            }
            case 5:
            {
                display(dq);
                break;
            }
            case 6:
            {
                data = peek_front(dq);
                if (data != -1)
                {
                    printf("Front element: %d\n", data);
                }
                break;
            }
            case 7:
            {
                data = peek_rear(dq);
                if (data != -1)
                {
                    printf("Rear element: %d\n", data);
                }
                break;
            }
            case 0:
            {
                printf("Exiting...\n");
                free(dq);
                return 0;
            }
            default:
            {
                printf("Invalid choice!\n");
            }
        }

    }
}


void enqueue_front(DQ *dq, int data)
{
    if ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->rear + 1 == dq->front))
    {
        printf("Deque overflow!\n");
    }
    else 
    {
        if (dq->front == -1)
        {
            dq->front = 0;
            dq->rear = 0;
        }
        else if (dq->front == 0)
        {
            dq->front = MAX_SIZE - 1;
        }
        else
        {
            dq->front--;
        }
        dq->items[dq->front] = data;
        printf("Enqueued at the front: %d\n", data);
    }
}


void enqueue_rear(DQ *dq, int data) {
    if ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->rear + 1 == dq->front))
    {
        printf("Deque overflow!\n");
    }
    else
    {
        if (dq->front == -1)
        {
            dq->front = 0;
            dq->rear = 0;
        }
        else if (dq->rear == MAX_SIZE - 1)
        {
            dq->rear = 0;
        }
        else
        {
            dq->rear++;
        }
        dq->items[dq->rear] = data;
        printf("Enqueued at the rear: %d\n", data);
    }
}


int dequeue_front(DQ *dq)
{
    int data = -1;
    if (dq->front == -1)
    {
        printf("Deque underflow!\n");
    }
    else
    {
        data = dq->items[dq->front];
        if (dq->front == dq->rear)
        {
            dq->front = -1;
            dq->rear = -1;
        }
        else if (dq->front == MAX_SIZE - 1)
        {
            dq->front = 0;
        }
        else
        {
            dq->front++;
        }
    }
    return data;
}


int dequeue_rear(DQ *dq)
{
    int data = -1;
    if (dq->front == -1)
    {
        printf("Deque underflow!\n");
    }
    else
    {
        data = dq->items[dq->rear];
        if (dq->front == dq->rear)
        {
            dq->front = -1;
            dq->rear = -1;
        }
        else if (dq->rear == 0)
        {
            dq->rear = MAX_SIZE - 1;
        }
        else
        {
            dq->rear--;
        }
    }
    return data;
}


void display(DQ *dq)
{
    if (dq->front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Deque elements: ");
        int i = dq->front;
        do
        {
            printf("%d ", dq->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        while (i != (dq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}


int peek_front(DQ *dq)
{
    if (dq->front == -1)
    {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->items[dq->front];

}


int peek_rear(DQ *dq) {
    if (dq->front == -1)
    {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->items[dq->rear];
}
