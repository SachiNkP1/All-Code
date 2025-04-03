#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m,o,data;
    struct Node{
        int data;
        struct Node * next;
    };
    struct Node * head=NULL, *temp=NULL, *newNode;
    printf("Enter no of nodes which you want to create: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter data %d ",i+1);
        scanf("%d",&data);
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
    printf("Linked list:[");
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("Null]");
    printf("\nHow many nodes do you want to create at the begining: ");
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        printf("Enter data %d :",i+1);
        scanf("%d",&data);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }
    temp=head;
    printf("\nLinked list after creating link at the begining:");
    printf("\nNew linked list:[");
    while (temp!=NULL)
    {
        printf("<--%d",temp->data);
        temp=temp->next;
    }
    printf("Null]");
    printf("\nCreating the link at the end..");
    printf("\nHow many nodes do you want to create at the end:");
    scanf("%d",&o);
    for (int i = 0; i < o; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        
    }
    temp=head;
    printf("\nLinked list after creating nodes at the end:");
    printf("\nLinked list:[");
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("Null]");
    
    return 0;
    
}