/*
 * Implementation of Stack using array
 * Authored by: Arup Sarkar
 * Created on: March 27, 2018
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void push(int);
int pop();
int peek();
void display();

int flag = 0;
int top = -1;
int stack[MAX];

int main()
{
    int choice, val;
    
    do
    {
        printf("\n 1.Push an element.");
        printf("\n 2. Pop an element.");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter a value to push: ");
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
                if(flag == 0)
                    printf("\nTop element in the stack: %d", val);
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
    if(top == MAX - 1)
    {
        printf("Stack OVERFLOW!");
        return;
    }
    stack[++top] = element;
}

int pop()
{
    flag = 0;
    if(top == -1)
    {
        flag = 1;
        printf("\nStack UNDERFLOW!");
        return -9999;
    }
    int val = stack[top--];
    return val;
}

int peek()
{
    flag = 0;
    if(top == -1)
    {
        flag = 1;
        printf("\nStack UNDERFLOW!");
        return -9999;
    }
    
    return stack[top];
}

void display()
{
    int i;
    printf("\n");
    for(i = top; i > -1; i--)
    {
        printf("%d\n",stack[i]);
    }
}
