/*
 * Programmed by: Arup Sarkar
 *
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int insert(struct node **, struct node **);
void search(int, struct node **);
struct node  *delete(struct node **);
void display(struct node **);

int main()
{
    int choice, val;

    struct node *first = NULL;
    struct node *last = NULL;

    do
    {
        printf("\n1. Insert Node");
        printf("\n2. Delete Node");
        printf("\n3. Display Nodes");
        printf("\n4. Search");
        printf("\n5. Exit");
        printf("\nGive your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert(&first, &last);
                break;
            case 2:
                delete(&first);
                break;
            case 3:
                printf("\n");
                display(&first);
                printf("\n");
                break;
            case 4:
                printf("\nEnter the value to search: ");
                scanf("%d", &val);
                search(val, &first);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice.....");
        }
    }while(1);

    return 0;
}

int insert(struct node **first, struct node **last)
{
    int val;

    printf("\nEnter a value: ");
    scanf("%d", &val);

    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;

    if(*first == NULL)
    {
        *first = *last = n;
    }
    else //if(*first == *last)
    {
        (*last)->next = n;
        *last = n;
    }


    return val;
}

struct node *delete(struct node **first)
{
    int val;
    printf("\nEnter a value that you want to delete: ");
    scanf("%d", &val);

    struct node *ptr = *first, *prev;
    if(ptr == NULL)
    {
        printf("\nEmpty List...");
        return NULL;
    }
    else if(ptr->next == NULL && ptr->data == val)
    {
        *first = NULL;
        printf("\nTarget deleted.\n");
        return ptr;
    }
    prev = *first;
    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            if(*first == ptr)
            {
                *first = ptr->next;
                printf("\nTarget deleted\n");
                return ptr;
            }
            prev->next = ptr->next;
            printf("\nTarget deleted\n");
            return ptr;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("\nTarget not found!\n");
    return NULL;
}

void display(struct node **first)
{
    struct node *ptr;
    ptr = *first;

    if(ptr == NULL)
    {
        printf("\nEmpty list...");
    }
    while(ptr != NULL)
    {
        printf("%d --> ", ptr->data);

        ptr = ptr->next;
    }
    printf("X");
}

void search(int val, struct node **first)
{
    struct node *ptr = *first;
    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            printf("\nTarget node found!\n");
            return val;
        }
        ptr = ptr->next;
    }
    printf("\nTarget node not found!\n");
}
