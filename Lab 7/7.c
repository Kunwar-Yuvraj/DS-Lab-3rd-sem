/*
Develop a menu driven program to implement Circular Double linked list
with Header node to perform various operations such as:

i) Insertion and Deletion at front/rear
ii) Insertion and Deletion at the specified position
iii) Delete by Key
iv) Search by key
v) Create an ordered list
vi) Reverse a list
vii) Creating a copy of the list
*/


#include <stdio.h>
#include <stdlib.h>


typedef
struct Node
{
    struct Node* plink;
    int data;
    struct Node* nlink;
}
NODE;


typedef
struct
{
    NODE* head;
}
CDLL;


NODE* create_node(int data)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    if (new == NULL)
    {
        printf("Memory allocation for node failed!\n");
        return NULL;
    }
    new->plink = NULL;
    new->data = data;
    new->nlink = NULL;

    return new;
}


CDLL* create_list()
{
    CDLL* list = (CDLL*)malloc(sizeof(CDLL));
    if (list == NULL)
    {
        printf("Memory allocation for circular linked list failed!\n");
        return NULL;
    }
    list->head = create_node(0);
    
    return list;
}


void display(CDLL* list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
    }
    else
    {
        NODE* curr = list->head->nlink;
        printf("Circular Doubly Linked List:\n");
        do
        {
            printf("%d <--> ", curr->data);
            curr = curr->nlink;
        } while (curr != list->head->nlink);
        printf("(%d)\n", curr->data);
    }
}


void insert_at_front(CDLL* list, int data)
{
    NODE* new = create_node(data);
    if (list->head->data == 0)
    {
        list->head->nlink = new;
        new->plink = new;
        new->nlink = new;
        list->head->data += 1;
    }
    else
    {
        NODE* front = list->head->nlink;
        NODE* tail = front->plink;
        new->nlink = front;
        front->plink = new;
        tail->nlink = new;
        new->plink = tail;
        list->head->nlink = new;
        list->head->data += 1;
    }
}


void delete_at_front(CDLL* list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return;
    }
    NODE* front = list->head->nlink;
    if (list->head->data == 1)
    {
        list->head->nlink = NULL;
        free(front);
        list->head->data -= 1;
    }
    else
    {
        NODE* tail = front->plink;
        front->nlink->plink = tail;
        tail->nlink = front->nlink;
        list->head->nlink = front->nlink;
        free(front);
        list->head->data -= 1;
    }
}


void insert_at_rear(CDLL* list, int data)
{
    if (list->head->data == 0)
    {
        insert_at_front(list, data);
    }
    else
    {
        NODE* new = create_node(data);
        NODE* front = list->head->nlink;
        NODE* tail = front->plink;
        tail->nlink = new;
        front->plink = new;
        new->nlink = front;
        new->plink = tail;
        list->head->data += 1;
    }
}


void delete_at_rear(CDLL* list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return;
    }
    NODE* front = list->head->nlink;
    NODE* tail = front->plink;
    front->plink = tail->plink;
    tail->plink->nlink = front;
    free(tail);
    list->head->data -= 1;
}


void insert_at_position(CDLL* list, int data, int pos)
{
    if (pos < 0 || pos > list->head->data)
    {
        printf("Invalid position!\n");
        return;
    }
    if (list->head->data == 0 || pos == 0)
    {
        insert_at_front(list, data);
    }
    else if (pos == list->head->data)
    {
        insert_at_rear(list, data);
    }
    else
    {
        NODE* new = create_node(data);
        NODE* curr = list->head->nlink;
        NODE* prev = NULL;
        while (pos)
        {
            prev = curr;
            curr = curr->nlink;
            pos--;
        }
        new->nlink = curr;
        new->plink = prev;
        prev->nlink = new;
        curr->plink = new;
        list->head->data += 1;
    }
}


void delete_at_position(CDLL* list, int pos)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return;
    }
    if (pos < 0 || pos >= list->head->data)
    {
        printf("Invalid position!\n");
    }
    else if (pos == 0)
    {
        delete_at_front(list);
    }
    else if (pos == list->head->data - 1)
    {
        delete_at_rear(list);
    }
    else
    {
        NODE* del = list->head->nlink;
        while (pos)
        {
            del = del->nlink;
            pos--;
        }
        del->plink->nlink = del->nlink;
        del->nlink->plink = del->plink;
        free(del);
        list->head->data -= 1;
    }
}


int search_by_key(CDLL* list, int key)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return -1;
    }
    int pos = 0;
    NODE* curr = list->head->nlink;
    do
    {
        if (key == curr->data)
        {
            return pos;
        }
        pos++;
        curr = curr->nlink;
    } while (curr != list->head->nlink);
    return -1;
}


void delete_by_key(CDLL* list, int key)
{
    int pos = search_by_key(list, key);
    if (pos != -1)
    {
        delete_at_position(list, pos);
    }
    else
    {
        printf("Key element not found!\n");
    }
}


void create_ordered_list(CDLL* list, int data)
{
    NODE* curr = list->head->nlink;
    int pos = 0;
    do
    {
        if (data < curr->data)
        {
            break;
        }
        pos++;
        curr = curr->nlink;
    } while (curr != list->head->nlink);

    insert_at_position(list, data, pos);
}


void reverse_list(CDLL* list)
{
    if 
    (
        list->head->data == 0
        || list->head->data == 1
    )
    {
        printf("Nothing to reverse!\n");
        return;
    }
    NODE* curr = list->head->nlink;
    NODE* tail = curr->plink;
    do
    {
        NODE* nlink = curr->nlink;
        NODE* plink = curr->plink;
        curr->nlink = plink;
        curr->plink = nlink;        
        curr = nlink;
    } while (curr != list->head->nlink);
    list->head->nlink = tail;
}


CDLL* copy_list(CDLL* list)
{
    CDLL* new_list = create_list();
    if (list->head->data == 0)
    {
        printf("Original list is empty!\n");
        return new_list;
    }
    NODE* curr = list->head->nlink;
    do
    {
        insert_at_rear(new_list, curr->data);
        curr = curr->nlink;
    } while (curr != list->head->nlink);
    return new_list;
}


int main()
{
    CDLL* list = create_list();
    printf("\nMAIN MENU :>\n\n");
    printf("1. Display\n");
    printf("2. Insert At Front\n");
    printf("3. Delete At Front\n");
    printf("4. Insert At Rear\n");
    printf("5. Delete At Rear\n");
    printf("6. Insert At Position\n");
    printf("7. Delete At Position\n");
    printf("8. Delete By Key\n");
    printf("9. Search By Key\n");
    printf("10. Create Ordered List\n");
    printf("11. Reverse List\n");
    printf("12. Copy List\n");
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
                display(list);
                break;
            }
            case 2:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                insert_at_front(list, data);
                printf("Inserted at front!\n");
                break;
            }
            case 3:
            {
                delete_at_front(list);
                printf("Deleted at front!\n");
                break;
            }
            case 4:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                insert_at_rear(list, data);
                printf("Inserted at rear!\n");
                break;
            }
            case 5:
            {
                delete_at_rear(list);
                printf("Deleted at rear!\n");
                break;
            }
            case 6:
            {
                int data, pos;
                printf("Enter data and position : ");
                scanf("%d %d", &data, &pos);
                insert_at_position(list, data, pos);
                printf("Inserted at position!\n");
                break;
            }
            case 7:
            {
                int pos;
                printf("Enter position : ");
                scanf("%d", &pos);
                delete_at_position(list, pos);
                printf("Deleted at position!\n");
                break;
            }
            case 8:
            {
                int key;
                printf("Enter key : ");
                scanf("%d", &key);
                delete_by_key(list, key);
                printf("Deleted by key!\n");
                break;
            }
            case 9:
            {
                int key;
                printf("Enter key : ");
                scanf("%d", &key);
                int pos = search_by_key(list, key);
                if (pos != -1)
                {
                    printf(
                        "Key %d found at position : %d\n", 
                        key, pos
                    );
                }
                else
                {
                    printf("Key element not found\n");
                }
                break;
            }
            case 10:
            {
                int data;
                printf("Enter data : ");
                scanf("%d", &data);
                create_ordered_list(list, data);
                printf("Inserted by order!\n");
                break;
            }
            case 11:
            {
                reverse_list(list);
                printf("Reversed!\n");
                break;
            }
            case 12:
            {
                CDLL* new_list = copy_list(list);
                printf("Copied!\n");
                display(new_list);
                free(new_list);
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