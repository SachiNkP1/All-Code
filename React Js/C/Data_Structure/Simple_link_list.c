#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
int main()
{
    int n;
    struct node* start = NULL;
    struct node* temp = NULL;
    struct node* newNode;

    printf("Enter 0 to exit the program: ");
    while (1)
    {
        printf("Enter data: ");
        scanf("%d",&n);
        if (n==0) break;
        newNode= (struct node*)malloc(sizeof(struct node));
        newNode ->data = n;
        newNode ->next = NULL;

        if (start == NULL)
        {
            start=newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp=newNode;
    }
    printf("\n[");
    temp=start;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("]");
    

}