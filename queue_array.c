/*
 * Implementation of Queue using array
 * Authored by: Arup Sarkar
 * Created on: April 10, 2018
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void enqueue(int);
int dequeue();
int peek();
void display();

int queue[MAX];
int front = -1;
int rear = -1;
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
    if(rear == MAX-1)
    {
        printf("\nOverflow!\n");
        return;
    }
    if(front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = rear + 1;
    queue[rear] = item;
}

int dequeue()
{
    flag = 0;
    if(front == -1 || front > rear)
    {
        printf("\nUnderflow!\n");
        flag = 1;
        return -9999;
    }
    int item = queue[front];
    front += 1;
    
    return item;
}

int peek()
{
    flag = 0;
    if(front == -1 || front > rear)
    {
        printf("\nUnderflow!\n");
        flag = 1;
        return -9999;
    }
    return queue[front];
}

void display()
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("\nEmpty queue!\n");
        return;
    }
    printf("\nItems of the queue:\n");
    for(i = front; i <= rear; i++)
        printf("%d\t", queue[i]);
    printf("\n");
}
