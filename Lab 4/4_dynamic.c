/*
Develop a menu driven program to implement the following operations on
array storage representation with dynamic memory allocation.

i)Insert by position
ii) Delete by position
iii) Insert by key
iv) Delete by key
v) Insert by order
vi) Search by key
vii) Search by position
viii) Reverse the contents.
*/


#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100


void display_array(int *, int);
void insert_by_position(int *, int *, int, int);
void delete_by_position(int *, int *, int);
int search_by_key(int *, int, int);
void insert_by_key(int *, int *, int, int);
void insert_by_key(int *, int *, int, int);
void delete_by_key(int *, int *, int);
void insert_by_order(int *, int *, int);
int search_by_position(int *, int, int);
void reverse_contents(int *, int);


int main()
{
    int size = 0;
    int *arr = (int *)malloc(MAX_SIZE * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("\nMAIN MENU :> \n\n");
    printf("1. Insert by Position\n");
    printf("2. Delete by Position\n");
    printf("3. Insert by Key\n");
    printf("4. Delete by Key\n");
    printf("5. Insert by Order\n");
    printf("6. Search by Key\n");
    printf("7. Search by Position\n");
    printf("8. Reverse the contents\n");
    printf("9. Display\n");
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
                int position, value;
                printf("Enter position and value to insert: ");
                scanf("%d %d", &position, &value);
                insert_by_position(arr, &size, position, value);
                break;
            }
            case 2:
            {
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_by_position(arr, &size, position);
                break;
            }
            case 3:
            {
                int key, value;
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert_by_key(arr, &size, key, value);
                break;
            }
            case 4:
            {
                int key;
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_by_key(arr, &size, key);
                break;
            }
            case 5:
            {
                int value;
                printf("Enter value to insert by order: ");
                scanf("%d", &value);
                insert_by_order(arr, &size, value);
                break;
            }
            case 6:
            {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                int position = search_by_key(arr, size, key);
                if (position != -1)
                {
                    printf("Key found at position: %d\n", position);
                } else
                {
                    printf("Key not found!\n");
                }
                break;
            }
            case 7:
            {
                int position;
                printf("Enter position to search: ");
                scanf("%d", &position);
                int value = search_by_position(arr, size, position);
                if (value != -1)
                {
                    printf("Value at position %d is : %d\n", position, value);
                }
                break;
            }
            case 8:
            {
                reverse_contents(arr, size);
                break;
            }
            case 9:
            {
                display_array(arr, size);
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

    free(arr);

    return 0;
}


void display_array(int *arr, int size)
{
    if (size == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}


void insert_by_position(int *arr, int *size, int position, int value)
{
    if (*size >= MAX_SIZE) {
        printf("Array is full. Insertion failed.\n");
        return;
    }

    if (position < 0 || position > *size)
    {
        printf("Invalid position for insertion.\n");
        return;
    }

    for (int i = *size - 1; i >= position; i--)
    {
        *(arr + i + 1) = *(arr + i);
    }

    *(arr + position) = value;
    (*size)++;
    printf("Inserted!\n");
}


void delete_by_position(int *arr, int *size, int position)
{
    if (*size <= 0 || position < 0 || position >= *size)
    {
        printf("Invalid position for deletion.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }

    *size -= 1;
    printf("Deleted!\n");
}


int search_by_key(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == key)
        {
            return i;
        }
    }
    
    return -1;
}


void insert_by_key(int *arr, int *size, int key, int value)
{
    int pos = search_by_key(arr, *size, key);
    if (pos != -1)
    {
        insert_by_position(arr, size, pos, value);
    }
    else
    {
        printf("Key element not found!\n");
    }
}


void delete_by_key(int *arr, int *size, int key)
{
    int pos = search_by_key(arr, *size, key);
    if (pos != -1)
    {
        delete_by_position(arr, size, pos);
    }
    else
    {
        printf("Key element not found!\n");
    }
}


void insert_by_order(int *arr, int *size, int value)
{
    int i = *size - 1;
    while (i >= 0 && *(arr + i) > value)
    {
        *(arr + i + 1) = *(arr + i);
        i--;
    }
    *(arr + i + 1) = value;
    *size += 1;
    printf("Inserted by order!\n");
}


int search_by_position(int *arr, int size, int position)
{
    if (position < 0 || position >= size)
    {
        printf("Invalid position for search.\n");
        return -1;
    }

    return *(arr + position);
}


void reverse_contents(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        printf("Reverse not possilbe!\n");
        return;
    }
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int temp = *(arr + start);
        *(arr + start) = *(arr + end);
        *(arr + end) = temp;
        start++;
        end--;
    }
    printf("Reversed!\n");
}
