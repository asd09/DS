/*
 * Implementation of Queue using array
 * Authored by: Arup Sarkar
 * Created on: April 10, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void enqueue(int);
int dequeue();
int peek();
void display();

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;
int flag = 0;

int main()
{
    int choice, val;
    do
    {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter a number to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(!flag)
                    printf("\nRemoved item from the queue: %d\n", val);
                break;
            case 3:
                val = peek();
                if(!flag)
                    printf("\nItem at the front of the queue: %d\n", val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid choice!");
        }
    }while(1);
    
    return 0;
}

void enqueue(int item)
{
    struct queue *n = (struct queue*)malloc(sizeof(struct queue));
    if(n == NULL)
    {
        printf("\nMemory Full!\n");
        return;
    }
    
    n->data = item;
    n->next = NULL;
    
    if(front == NULL)
    {
        front = rear = n;
        return;
    }
    rear->next = n;
    rear = n;
}

int dequeue()
{
    flag = 0;
    int item;
    if(front == NULL)
    {
        printf("\nUnderflow!\n");
        flag = 1;
        return -9999;
    }
    struct queue *ptr = front;
    front = front->next;
    item = ptr->data;
    free(ptr);
    return item;
}

int peek()
{
    flag = 0;
    if(front == NULL)
    {
        printf("\nUnderflow!\n");
        flag = 1;
        return -9999;
    }
    return front->data;
}

void display()
{
    if(front == NULL)
    {
        printf("\nUnderflow!\n");
        return;
    }
    struct queue *ptr = front;
    printf("\n");
    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
