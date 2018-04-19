/*
 * Programmed By: Arup Sarkar
 * Doubly Linked List.
 * 
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int take_value()
{
    int val;
    printf("\nEnter an integer value: ");
    scanf("%d", &val);
    return val;
}
struct node *create_node()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("\nSorry! Can't create a node at this point...\n Exiting from the program...");
        exit(1);
    }
    return n;
}

void display(struct node **first)
{
    struct node *ptr = *first;
    if(*first == NULL)
    {
        printf("\nEmpty List!\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf(" %d <-->",ptr->data);
        ptr = ptr->next;
    }
    printf("X\n");
}
struct node *search(struct node **first, int val)
{
    if(*first == NULL)
    {
        //printf("\nEmpty List!\nTry to create some node first.\n");
        return *first;
    }
    struct node *ptr = *first;
    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            printf("\nSearched node found...\n");
            return ptr;
        }
        ptr = ptr->next;
    }
    printf("\nSearched node not found...");
    printf("\nTry again.\n");
    return NULL;
}
struct node *insert_beg(struct node **first, int val)
{    
    struct node *n = create_node();
    n->data = val;
    n->next = *first;
    n->prev = NULL;
    if(*first != NULL)
        (*first)->prev = n; 
    *first = n;
    
    return *first;
}
struct node *insert_end(struct node **first, int val)
{
    struct node *n = create_node();
    n->data = val;
    n->next = NULL;
    if(*first == NULL)
    {
        *first = n;
        n->prev = NULL;
        return *first;
    }
    struct node *ptr = *first;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->prev = ptr;
    
    return *first;
}

struct node *insert_after_node(struct node **first, int val)
{
    int target;
    printf("\nEnter the value of the node after which you want to insert the node: ");
    scanf("%d", &target);
    
    struct node *ptr = search(&(*first), target);
    if(ptr == NULL)
    {
        printf("\nTarget node does not exist.\n");
        return *first;
    }
    struct node *n = create_node();
    n->data = val;
    n->next = ptr->next;
    n->prev = ptr;
    if(ptr->next != NULL)
    ptr->next->prev = n;
    ptr->next = n;
    
    return *first;
}

struct node *insert_before_node(struct node **first, int val)
{
    int target;
    printf("\nEnter the value of the node before which you want to insert the node: ");
    scanf("%d", &target);
    struct node *ptr = search(&(*first), target);
    if(ptr == NULL)
    {
        printf("\nTarget node does not exist.\n");
        return *first;
    }
    struct node *n = create_node();
    n->data = val;
    n->next = ptr;
    //printf("%d\n", n->next->data); // DEBUG POINT
    if(ptr->prev != NULL)
        ptr->prev->next = n;
    n->prev = ptr->prev;
    ptr->prev = n;
    *first = n;
    
    return *first;
}

struct node *delete_first(struct node **first)
{
    if(*first == NULL)
    {
        printf("\nEmpty List!\n");
        return NULL;
    }
    
    if((*first)->next == NULL)
    {
       // printf("\nTEST POINT 2...\n");
        free(*first);
        *first = NULL;
        return *first;
    }
    struct node *ptr = *first;
    *first = ptr->next;
    (*first)->prev = NULL;
    free(ptr);
    
    return *first;
}
struct node *delete_last(struct node **first)
{
    if(*first == NULL)
    {
        printf("\nEmpty List!\n");
        return NULL;
    }
    if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return *first;
    }
    struct node *ptr = *first;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    
    return *first;
}
struct node *delete_after_node(struct node **first, int val)
{
    if(*first == NULL)
    {
        printf("\nEmpty List!\n");
        return *first;
    }
    
    struct node *ptr = *first;
    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            if(ptr->next == NULL)
            {
                printf("\nNo node exists after the target node.\n");
                printf("\nNothing to delete at this point...\n");
                return *first;
            }
            struct node *temp = ptr->next;
            ptr->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = ptr;
            free(temp);
            return *first;
        }
        ptr = ptr->next;
    }
    printf("\nNode not found!\n");
    return *first;
}
struct node *delete_before_node(struct node **first, int val)
{
    if(*first == NULL)
    {
        printf("\nEmpty List!\n");
        return *first;
    }
    
    struct node *ptr = *first;
    while(ptr != NULL)
    {
        if(ptr->data == val)
        {
            if(ptr->prev == NULL)
            {
                printf("\nNo node exists before the target node.\n");
                printf("\nNothing to delete at this point...\n");
                return *first;
            }
            struct node *temp = ptr->prev;
            ptr->prev = temp->prev;
            if(temp->prev != NULL)
                temp->prev->next = ptr;
            else
                *first = ptr;
            free(temp);
            return *first;
        }
        ptr = ptr->next;
    }
    printf("\nNode not found!\n");
    return *first;
}

struct node *delete_node(struct node **first, int val)
{
    if(*first == NULL)
    {
        printf("\nEmpty List!\n");
        return *first;
    }
    struct node *ptr = *first;
    while(ptr!=NULL)
    {
        if(ptr->data == val)
        {
            if(ptr->next == NULL && ptr->prev == NULL)
            {
                *first = NULL;
                free(ptr);
                return *first;
            }
            if(ptr->next == NULL)
            {
                ptr->prev->next = NULL;
                free(ptr);
                return *first;
            }
            if(ptr->prev == NULL)
            {
                *first = ptr->next;
                ptr->next->prev = NULL;
                return *first;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            return *first;
            
        }
        ptr = ptr->next;
    }
    printf("\nNode not found!\n");
    return *first;
}

int main()
{
    int choice, val;
    struct node *first = NULL;
    struct node *n = NULL;
    //printf("Inside main");
    do
    {
        printf("\n 1. Insert node at the beginning");
        printf("\n 2. Insert node at the end");
        printf("\n 3. Insert after a given node");
        printf("\n 4. Insert before a given node");
        printf("\n 5. Delete first node");
        printf("\n 6. Delete last node");
        printf("\n 7. Delete after a given node");
        printf("\n 8. Delete before a given node");
        printf("\n 9. Delete a given node");
        printf("\n 10. Search");
        printf("\n 11. Display");
        printf("\n 12. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                val = take_value();
                insert_beg(&first, val);
                break;
            case 2:
                val = take_value();
                insert_end(&first, val);
                break;
            case 3:
                val = take_value();
                insert_after_node(&first, val);
                break;
            case 4:
                val = take_value();
                insert_before_node(&first, val);
                break;
            case 5:
                delete_first(&first);
                break;
            case 6:
                delete_last(&first);
                break;
            case 7:
                val = take_value();
                delete_after_node(&first, val);
                break;
            case 8:
                val = take_value();
                delete_before_node(&first, val);
                break;
            case 9:
                val = take_value();
                delete_node(&first, val);
                break;
            case 10:
                val = take_value();
                search(&first, val);
                break;
            case 11:
                display(&first);
                break;
            case 12:
                exit(1);
            default:
                printf("\nInvalid choice!");
        }
    }while(1);
    return 0;
}