/*
 * Implementation of stack using Linked List
 * Authored by: Arup Sarkar
 * Created on: March 27, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void push(int);
int pop();
int peek();
void display();

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
int flag = 0;

int main()
{
    int choice, val;
    
    do
    {
        printf("\n 1. Push");    
        printf("\n 2. Pop");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter a number to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if(flag == 0)
                    printf("\nRemoved item: %d", val);
                break;
            case 3:
                val = peek();
                if(!flag)
                    printf("\nValue at the top of the stack is: %d", val);
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

void push(int element)
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    if(n == NULL)
    {
        printf("\nStack OVERFLOW!");
        return;
    }
    n->data = element;
    n->next = NULL;
    if(top != NULL)
        n->next = top;
    top = n;
}

int pop()
{
    flag = 0;
    if(top == NULL)
    {
        printf("\nStack UNDERFLOW!");
        flag = 1;
        return -9999;
    }
    int val = top->data;
    struct stack *ptr = top;
    top = top->next;
    free(ptr);
    return val;
}

int peek()
{
    flag = 0;
    if(top == NULL)
    {
        printf("\nStack UNDERFLOW!");
        flag = 1;
        return -9999;
    }
    return top->data;
}

void display()
{
    if(top == NULL)
    {
        printf("\nStack UNDERFLOW!");
        return;       
    }
    struct stack *ptr = top;
    while(ptr != NULL)
    {
        printf(" %d\n", ptr->data);
        ptr = ptr->next;
    }
}