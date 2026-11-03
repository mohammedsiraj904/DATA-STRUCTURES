
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_end(int data)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void create()
{
    int n, i, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        insert_end(data);
    }
}

void insert_first(int data)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}




void insert_position(int data, int pos)
{
    struct node *newnode, *temp;
    int i;

    if(pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        insert_first(data);
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}


void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
void delete_first()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted successfully\n");
}

void delete_end()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    if(head->next == NULL)
    {
        head = NULL;
        free(temp);

        printf("Node deleted successfully\n");
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("Node deleted successfully\n");
}
void delete_position(int pos)
{
    struct node *temp, *prev;
    int i;

    if(head == NULL || pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        delete_first();
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted successfully\n");
}


int main()
{
    int choice, data, pos;

    while(1)
    {
        printf("\n SINGLY LINKED LIST ");
        printf("\n1. Create");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at Any Position");
        printf("\n4. Insert at End");
        printf("\n5. Delete at Beginning");
        printf("\n6. Delete at Any Position");
        printf("\n7. Delete at End");
        printf("\n8. Display");
        printf("\n9. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_first(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &pos);

                insert_position(data, pos);
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 5:
                delete_first();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);

                delete_position(pos);
                break;

            case 7:
                delete_end();
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
