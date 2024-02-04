/*
Develop a menu driven program to implement Circular singly linked list with
various operations such as (Note: Use Header node to simplify he complex
operations)

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
    int data;
    struct Node *link;
}
NODE;


typedef
struct
{
    NODE *head;
}
CLL;


NODE * create_node(int);
CLL * create_list();
void display(CLL *);
void insert_at_front(CLL *, int);
int delete_at_front(CLL *);
void insert_at_rear(CLL *, int);
int delete_at_rear(CLL *);
int insert_at_position(CLL *, int, int);
int delete_at_position(CLL *, int);
int search_by_key(CLL *, int);
int delete_by_key(CLL *, int);
void create_ordered_list(CLL *, int);
int reverse_list(CLL *);
CLL * copy_list(CLL *);


int main()
{
    CLL *list = create_list();

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
                int delete = delete_at_front(list);
                if (delete)
                {
                    printf("Deleted at front!\n");
                }
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
                int delete = delete_at_rear(list);
                if (delete)
                {
                    printf("Deleted at rear!\n");
                }
                break;
            }
            case 6:
            {
                int data, pos;
                printf("Enter data and position : ");
                scanf("%d %d", &data, &pos);
                int insert = insert_at_position(list, data, pos);
                if (insert)
                {
                    printf("Inserted at position %d!\n", pos);
                }
                break;
            }
            case 7:
            {
                int pos;
                printf("Enter position : ");
                scanf("%d", &pos);
                int delete = delete_at_position(list, pos);
                if (delete)
                {
                    printf("Deleted at position %d!\n", pos);
                }
                break;
            }
            case 8:
            {
                int key;
                printf("Enter key : ");
                scanf("%d", &key);
                int delete = delete_by_key(list, key);
                if (delete)
                {
                    printf("Element %d deleted!\n", key);
                }
                else
                {
                    printf("Element %d not found!\n", key);
                }
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
                    printf("Element %d found at position : %d!\n", key, pos);
                }
                else
                {
                    printf("Element %d not found!\n", key);
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
                int reverse = reverse_list(list);
                if (reverse)
                {
                    printf("Reversed!\n");
                }
                break;
            }
            case 12:
            {
                CLL *copied_list = copy_list(list);
                printf("Copied!\n");
                display(copied_list);
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


NODE * create_node(int data)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    if (new == NULL)
    {
        printf("Memory allocation for node failed!\n");
        return NULL;
    }
    new->data = data;
    new->link = NULL;

    return new;
}


CLL * create_list()
{
    CLL *list = (CLL *)malloc(sizeof(CLL));
    if (list == NULL)
    {
        printf("Memory allocation for list failed!\n");
        return NULL;
    }
    list->head = create_node(0);

    return list;
}


void display(CLL *list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return;
    }
    NODE *curr = list->head->link;
    printf("Circular Singly Linked List :\n");
    do
    {
        printf("%d -> ", curr->data);
        curr = curr->link;
    } while (curr != list->head->link);
    printf("(%d)\n", curr->data);
}


void insert_at_front(CLL *list, int data)
{
    NODE *new = create_node(data);
    if (list->head->data == 0)
    {
        list->head->link = new;
        new->link = new;
    }
    else
    {
        NODE *tail = list->head->link;
        while (tail->link != list->head->link)
        {
            tail = tail->link;
        }
        new->link = list->head->link;
        list->head->link = new;
        tail->link = new;
    }
    list->head->data += 1;
}


int delete_at_front(CLL *list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    NODE *front = list->head->link;
    NODE *tail = list->head->link;
    while (tail->link != list->head->link)
    {
        tail = tail->link;
    }
    tail->link = front->link;
    list->head->link = front->link;
    free(front);
    list->head->data -= 1;

    return 1;
}


void insert_at_rear(CLL *list, int data)
{
    if (list->head->data == 0)
    {
        insert_at_front(list, data);
        return;
    }
    NODE *new = create_node(data);
    NODE *tail = list->head->link;
    while (tail->link != list->head->link)
    {
        tail = tail->link;
    }
    tail->link = new;
    new->link = list->head->link;
    list->head->data += 1;
}


int delete_at_rear(CLL *list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    else if (list->head->data == 1)
    {
        delete_at_front(list);
        return 1;
    }
    else
    {
        NODE *tail = list->head->link;
        NODE *prev = NULL;
        while (tail->link != list->head->link)
        {
            prev = tail;
            tail = tail->link;
        }
        prev->link = list->head->link;
        free(tail);
        list->head->data -= 1;
    }
}


int insert_at_position(CLL *list, int data, int pos)
{
    if (pos < 0 || pos > list->head->data)
    {
        printf("Invalid position for insertion!\n");
        return 0;
    }
    if (pos == 0)
    {
        insert_at_front(list, data);
        return 1;
    }
    else if (pos == list->head->data)
    {
        insert_at_rear(list, data);
        return 1;
    }
    else
    {
        NODE* new = create_node(data);
        NODE* curr = list->head->link;
        NODE* prev = NULL;
        while (pos--)
        {
            prev = curr;
            curr = curr->link;
        }
        prev->link = new;
        new->link = curr;
        list->head->data += 1;

        return 1;
    }
}


int delete_at_position(CLL *list, int pos)
{
    if (pos < 0 || pos >= list->head->data)
    {
        printf("Invalid position!\n");
        return 0;
    }
    if (pos == 0)
    {
        delete_at_front(list);
        return 1;
    }
    else if (pos == list->head->data - 1)
    {
        delete_at_rear(list);
        return 1;
    }
    else
    {
        NODE* curr = list->head->link;
        NODE* prev = NULL;
        while (pos--)
        {
            prev = curr;
            curr = curr->link;
        }
        prev->link = curr->link;
        free(curr);
        list->head->data -= 1;
    }
}


int search_by_key(CLL *list, int key)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    NODE *curr = list->head->link;
    int pos = 0;
    do
    {
        if (key == curr->data)
        {
            return pos;
        }
        curr = curr->link;
        pos++;
    } while (curr != list->head->link);

    return -1;
}


int delete_by_key(CLL *list, int key)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    int pos = search_by_key(list, key);
    if (pos != -1)
    {
        return delete_at_position(list, pos);
    }
    return 0;
}


void create_ordered_list(CLL *list, int data)
{
    if (list->head->data == 0)
    {
        insert_at_front(list, data);
    }
    NODE *curr = list->head->link;
    int pos = 0;
    do
    {
        if (data < curr->data)
        {
            break;
        }
        pos++;
        curr = curr->link;
    } while (curr != list->head->link);
    insert_at_position(list, data, pos);
}


int reverse_list(CLL *list)
{
    if
    (
        list->head->data == 0
        || list->head->data == 1
    )
    {
        printf("Nothing to reverse!\n");
        return 0;
    }
    NODE *prev = NULL;
    NODE *curr = list->head->link;
    NODE *next = NULL;
    do
    {
        next = curr->link;
        curr->link = prev;

        prev = curr;
        curr = next;
    } while (curr != list->head->link);
    list->head->link = prev;
    curr->link = prev;
    return 1;
}


CLL * copy_list(CLL *list)
{
    CLL *copied_list = create_list();
    if (list->head->data == 0)
    {
        printf("Original list is empty!\n");
        return copied_list;
    }
    NODE *curr = list->head->link;
    do
    {
        insert_at_rear(copied_list, curr->data);
        curr = curr->link;
    } while (curr != list->head->link);
    return copied_list;
}