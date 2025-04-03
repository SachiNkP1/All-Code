//Stack using switch case
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1, choice, num;

int main() {
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3.Peek (view top element)\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top == SIZE - 1)
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Enter the element to be pushed: ");
                scanf("%d", &stack[++top]);
            }
            break;
        case 2:
            if (top == -1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Popped element is: %d\n", stack[top--]);
            }
            break;
        case 3:
            if (top == -1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Top element is: %d\n", stack[top]);
            }
            break;
        case 4:
            if (top == -1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack elements are: ");
                for (int i = 0; i <= top; i++)
                {
                    printf("%d ", stack[i]);
                }
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}