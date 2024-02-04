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
    NODE* head;
}
LIST;


NODE * create_node(int);
LIST * create_list();
void display(LIST *);
void insert_at_front(LIST *, int);
int delete_at_front(LIST *);
void insert_at_rear(LIST *, int);
int delete_at_rear(LIST *);
int insert_at_position(LIST *, int, int);
int delete_at_position(LIST *, int);
int search_by_key(LIST *, int);
int delete_by_key(LIST *, int);
void create_ordered_list(LIST *, int);
int reverse_list(LIST *);
LIST * copy_list(LIST *);


int main()
{
    LIST *list = create_list();

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
                LIST *copied_list = copy_list(list);
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
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL)
    {
        printf("Memory allocation for node failed!\n");
        return NULL;
    }
    node->data = data;
    node->link = NULL;

    return node;
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

    return list;
}


void display(LIST *list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return;
    }
    printf("Singly Linked List :\n");
    NODE *curr = list->head->link;
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->link;
    }
    printf("NULL\n");
}


void insert_at_front(LIST *list, int data)
{
    NODE *new = create_node(data);
    if (list->head->data == 0)
    {
        list->head->link = new;
    }
    else
    {
        new->link = list->head->link;
        list->head->link = new;
    }
    list->head->data += 1;
}


int delete_at_front(LIST *list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    NODE *front = list->head->link;
    list->head->link = front->link;
    free(front);
    list->head->data -= 1;

    return 1;
}


void insert_at_rear(LIST *list, int data)
{
    if (list->head->data == 0)
    {
        insert_at_front(list, data);
        return;
    }
    NODE *new = create_node(data);
    NODE *tail = list->head->link;
    while (tail->link != NULL)
    {
        tail = tail->link;
    }
    tail->link = new;
    list->head->data += 1;
}


int delete_at_rear(LIST *list)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    NODE *tail = list->head->link;
    NODE *prev = NULL;
    while (tail->link != NULL)
    {
        prev = tail;
        tail = tail->link;
    }
    prev->link = NULL;
    free(tail);
    list->head->data -= 1;

    return 1;
}


int insert_at_position(LIST *list, int data, int pos)
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
        NODE *new = create_node(data);
        NODE *curr = list->head->link;
        NODE *prev = NULL;
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


int delete_at_position(LIST *list, int pos)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    if (pos < 0 || pos >= list->head->data)
    {
        printf("Invalid position for deletion!\n");
        return 0;
    }
    else if (pos == 0)
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
        NODE *del = list->head->link;
        NODE *prev = NULL;
        while (pos--)
        {
            prev = del;
            del = del->link;
        }
        prev->link = del->link;
        free(del);
        list->head->data -= 1;
        
        return 1;
    }
}


int search_by_key(LIST *list, int key)
{
    if (list->head->data == 0)
    {
        printf("List is empty!\n");
        return 0;
    }
    NODE *curr = list->head->link;
    int pos = 0;
    while (curr != NULL)
    {
        if (key == curr->data)
        {
            return pos;
        }
        curr = curr->link;
        pos++;
    }

    return -1;
}


int delete_by_key(LIST *list, int key)
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


void create_ordered_list(LIST *list, int data)
{
    if (list->head->data == 0)
    {
        insert_at_front(list, data);
    }
    NODE *curr = list->head->link;
    int pos = 0;
    while (curr != NULL)
    {
        if (data < curr->data)
        {
            break;
        }
        pos++;
        curr = curr->link;
    }
    insert_at_position(list, data, pos);
}


int reverse_list(LIST *list)
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
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;

        prev = curr;
        curr = next;
    }
    list->head->link = prev;
    
    return 1;
}


LIST * copy_list(LIST *list)
{
    LIST *copied_list = create_list();
    if (list->head->data == 0)
    {
        printf("Original list is empty!\n");
        return copied_list;
    }
    NODE *curr = list->head->link;
    while (curr != NULL)
    {
        insert_at_rear(copied_list, curr->data);
        curr = curr->link;
    }
    return copied_list;
}