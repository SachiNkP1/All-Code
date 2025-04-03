//Simple stack program using array without functions
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1, choice, num;

int main() {
    printf("Enter the number of elements to be pushed: ");
    scanf("%d", &num);
    // Check if stack is full
    if (top == SIZE - 1)
    {
        printf("Stack is full\n");
    }
    // Check if stack is empty
    else if (top == -1)
    {
        printf("Stack is empty\n");    
    }
    // Push elements into stack
    else
    {
        for (int i = 0; i < num; i++)
        {
            printf("Enter the element to be pushed: ");
            scanf("%d", &stack[++top]);
        }
    }
    // Display stack elements
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    // Pop elements from stack
    printf("Enter the number of elements to be popped: ");
    scanf("%d", &num);
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            printf("Popped element is: %d\n", stack[top--]);
        }
    }
    // Display stack elements
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    return 0;
}


