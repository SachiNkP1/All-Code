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

    printf("\nDeleting the node at the end..");
    temp=head;
    if (head==NULL)
    {
        printf("There is no link..");
    }
    struct Node * prev;
    while (temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if (prev!=NULL)
    {
        prev->next=NULL;
    }
    free(temp);
    
    
    temp=head;
    printf("\nLinked list after deleting the node:[");
    while (temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("Null]");

    
    return 0;
    
}