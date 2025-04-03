#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, data;
    struct Node
    {
        int data;
        struct Node *next;
    };

    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter value of n which define how many nodes you want to create: ");
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data %d: ", i + 1);
        scanf("%d",&data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp = head;
    printf("Linked List ->[");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("Null]");
    return 0;
}