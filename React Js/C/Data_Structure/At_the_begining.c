#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *start = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;
    int choice, data;

    while(1)
    {
        printf("1. Create a new node\n");
        printf("2. Print the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter the data: ");
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;

                if(start == NULL)
                {
                    start = newNode;
                    temp = newNode;
                }
                else
                {
                    temp->next = newNode;
                    temp = newNode;
                }
                break;

            case 2:
                temp = start;
                while(temp != NULL)
                {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
                break;

            case 3:
                newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter the data: ");
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = start;
                start = newNode;
                break;

            case 4:
                newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter the data: ");
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;

                if(start == NULL)
                {
                    start = newNode;
                    temp = newNode;
                }
                else
                {
                    temp = start;
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
                break;

            case 5:
                if(start == NULL)
                {
                    printf("The list is empty\n");
                }
                else
                {
                    int key;
                    printf("Enter the key to delete: ");
                    scanf("%d", &key);

                    if(start->data == key)
                    {
                        temp = start;
                        start = start->next;
                        free(temp);
                    }
                    else
                    {
                        temp = start;
                        while(temp->next != NULL && temp->next->data != key)
                        {
                            temp = temp->next
                        }
                        if(temp->next == NULL)
                        {
                            printf("Key not found\n");
                        }
                        else
                        {
                            struct Node *del = temp->next;
                            temp->next = temp->next->next;
                            free(del);
                        }
        }
    }
}

