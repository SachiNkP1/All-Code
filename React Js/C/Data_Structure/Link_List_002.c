#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct Node
    {
        int data;
        struct Node *next;
    };
    int i, n, m, data;
    struct Node *head = NULL, *temp = NULL,*newNode;
    printf("Enter number of nodes which you want to link: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data %d ",i+1);
        scanf("%d",&data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=NULL;
        if (head==NULL)
        {
            head=newNode;
            temp=head;
        }
        else{
            temp->next=newNode;
            temp=temp->next;
        }
        
    }
    temp=head;
    printf("Linked List: [");
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("Null]");
     
    printf("\nInserting new node at the begining..");
    printf("\nHow many node which you want to insert at the begining: ");
    scanf("%d",&m);
    for ( i = 0; i < m; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data %d : ",i+1);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }
    temp=head;
    printf("\nLinked List: [");
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("Null]");
       
    return 0;
    


    
}