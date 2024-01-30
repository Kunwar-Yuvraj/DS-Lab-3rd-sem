/*
Develop a menu driven program to implement singly linked list with various
operations such as
i) Insertion and Deletion at front/rear
ii) Insertion and Deletion at the specified position
iii) Delete by Key
iv) Search by key
v) Create an ordered list
vi) Reverse a list
vii) Creating a copy of the list
*/


#include<stdio.h>
#include<stdlib.h>


int count = 0;


typedef
struct Node
{
    int data;
    struct Node* link;
}
NODE;


typedef
struct
{
    NODE* head;
}
LIST;


NODE * create_node(int newData)
{
    NODE * new = (NODE *)malloc(sizeof(NODE));
    if (new == NULL)
    {
        printf("Memory allocation for node failed!\n");
        return NULL;
    }
    new->data = newData;
    new->link = NULL;
    return new;
}


LIST * create_list()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list == NULL)
    {
        printf("Memory allocation for list failed!\n");
        return NULL;
    }
    list->head = create_node(0);
}


void display_list(LIST* list)
{
    NODE* curr = list->head->link;
    printf("Linked List:\n");
    if (list->head->link == NULL)
    {
        printf("NULL\n");
        return;
    }
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->link;
    }
    printf("NULL\nNumber of elements: %d\n", count);
}


void insert_at_rear(LIST* list, int newData)
{
    NODE* new = create_node(newData);
    if (list->head->link == NULL)
    {
        list->head->link = new;
        count++;
        printf("Node added in empty list!\n");
        return;
    }
    NODE* curr = list->head->link;
    while (curr->link != NULL)
    {
        curr = curr->link;
    }
    curr->link = new;
    count++;
    printf("NODE added successfully!\n");
}


void insert_at_front(LIST* list, int newData)
{
    NODE* new = create_node(newData);
    new->link = list->head->link;
    list->head->link = new;
    count++;
    printf("NODE added successfully!\n");
}


void delete_at_front(LIST* list)
{
    if (list->head->link == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    NODE* temp = list->head->link;
    list->head->link = list->head->link->link;
    free(temp);
    count--;
    printf("NODE at front deleted successfully!\n");
}


void delete_at_rear(LIST* list)
{
    if (list->head->link == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    NODE* curr = list->head->link;
    NODE* temp = curr->link;
    while (temp->link != NULL)
    {
        curr = curr->link;
        temp = temp->link;
    }

    curr->link = NULL;
    free(temp);
    count--;
    printf("NODE at Rear deleted successfully!\n");
}



void insert_at_position(LIST* list, int data, int pos)
{
    if (pos < 0 || pos > count)
    {
        printf("Invalid position to insert!\n");
        return;
    }
    if (pos == 0)
    {
        insert_at_front(list, data);
        return;
    }
    NODE* new = create_node(data);
    NODE* curr = list->head->link;
    while (pos-1)
    {   
        curr = curr->link;
        pos--;
    }
    new->link = curr->link;
    curr->link = new;
    count++;
    printf("Node added successfully!\n");  
}


void delete_at_position(LIST* list, int pos)
{
    if (list->head->link == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    
    if (pos < 0 || pos >= count)
    {
        printf("Invalid pos to delete!\n");
    }
    else if (pos == 0)
    {
        delete_at_front(list);
    }
    else if (pos == count - 1)
    {
        delete_at_rear(list);
    }
    else
    {
        NODE* curr = list->head->link;
        NODE* temp = curr->link;
        while (pos - 1)
        {
            curr = curr->link;
            temp = temp->link;
            pos--;
        }
        curr->link = temp->link;
        free(temp);
        count--;
        printf("Node deleted successfully!\n");
    }
}


void insert_ordered(LIST* list, int newData)
{
    if(list->head->link == NULL || newData < list->head->link->data)
    {
        insert_at_front(list, newData);
        return;
    }
    NODE* curr = list->head->link;
    NODE* new = create_node(newData);

    while (curr->link != NULL && curr->link->data < newData)
    {
        curr = curr->link;
    }
    new->link = curr->link;
    curr->link = new;
    count++;
    printf("Insertion successful!\n");
}


void reverse_list(LIST* list)
{
    NODE* prev = NULL;
    NODE* curr = list->head->link;
    NODE* next = NULL;

    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    list->head->link = prev;
    printf("List is reversed!\n");
}


LIST* copy_list(LIST* list)
{
    LIST* copiedList = (LIST*)malloc(sizeof(LIST));
    if (copiedList == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    copiedList->head = list->head->link;
    NODE* current1 = list->head->link;
    NODE* current2 = copiedList->head;

    while (current1->link != NULL)
    {
        current1 = current2;
        current1 = current1->link;
        current2 = current2->link;
    }
    printf("List copied!\n");
    return copiedList;
}


void search_by_key(LIST* list, int key) {
    if (list == NULL || list->head->link == NULL) {
        printf("List is empty!\n");
        return;
    }
    int pos = 0;
    NODE* curr = list->head->link;
    while (curr != NULL) {
        if (curr->data == key) {
            printf("Key %d found at position: %d!\n", key, pos);
            return;
        }
        pos++;
        curr = curr->link;
    }
    printf("Key %d not found in the list!\n", key);
}



int main()
{
    LIST* list = (LIST *)malloc(sizeof(LIST));
    if (list == NULL)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }
    list->head = (NODE*)malloc(sizeof(NODE));
    if (list->head == NULL) 
    {
        printf("Memory allocation for list->head failed!\n");
        return -1;
    }
    list->head->link = NULL;
    int choice;
    printf("\nMAIN MENU :>\n\n");
    printf("1. Insert At Rear\n");
    printf("2. Display List\n");
    printf("3. Insert At Front\n");
    printf("4. Delete At Front\n");
    printf("5. Delete At Rear\n");
    printf("6. Insert At Position\n");
    printf("7. Delete At Position\n");
    printf("8. Insert By Order\n");
    printf("9. Reverse List\n");
    printf("10. Copy List\n");
    printf("11. Search By Key\n");
    printf("0. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                int newData;
                printf("\nEnter NODE Data to insert: ");
                scanf("%d", &newData);
                insert_at_rear(list, newData);
                break;
            }
            case 2:
            {
                display_list(list);
                break;
            }
            case 3:
            {
                int newData;
                printf("\nEnter NODE Data to insert: ");
                scanf("%d", &newData);
                insert_at_front(list, newData);
                break;
            }
            case 4:
            {
                delete_at_front(list);
                break;
            }
            case 5:
            {
                delete_at_rear(list);
                break;
            }
            case 6:
            {
                int newData, pos;
                printf("\nEnter NODE pos and node data: ");
                scanf("%d %d", &pos, &newData);
                insert_at_position(list, newData, pos);
                break;
            }
            case 7:
            {
                int pos;
                printf("\nEnter NODE pos to delete: ");
                scanf("%d", &pos);
                delete_at_position(list, pos);
                break;
            }
            case 8:
            {
                int newData;
                printf("\nEnter NODE Data to insert by order: ");
                scanf("%d", &newData);
                insert_ordered(list, newData);
                break;
            }
            case 9:
            {
                reverse_list(list);
                break;
            }
            case 10:
            {
                LIST* copiedList = copy_list(list);
                display_list(copiedList);
                break;
            }
            case 11:
            {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                search_by_key(list, key);
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

    free(list);
    return 0;
}