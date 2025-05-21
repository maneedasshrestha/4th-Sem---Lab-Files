#include<stdio.h>

#define SIZE 20

int stack[SIZE];
int top = -1;
void push(int value)
{
    if (top < SIZE - 1)
    {
        top++;
        stack[top] = value;
    }
    else
    {
        printf("Stack is full \n");
    }
}
void pop()
{
    if (top >= 0)
    {
        printf(" Popped : %d\n", stack[top]);
        top--;
    }
    else
    {
        printf(" Stack is empty \n");
    }
}
void display()
{
    if (top >= 0)
    {
        printf(" Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n ");
    }
    else
    {
        printf(" Stack is empty\ n");
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    display(); // Stack: 10 20 30
    pop();     // Popped : 30
    display(); // Stack: 10 20
    return 0;
}