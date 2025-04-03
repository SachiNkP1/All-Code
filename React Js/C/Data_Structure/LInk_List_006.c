#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m,o,data,pos;
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

    printf("\nDeleting the node at the given position..");
    temp=head;
    if (head==NULL)
    {
        printf("There is no link..");
    }
    struct Node * prev;
    printf("\nEnter position no to delete that node: ");
    scanf("%d",&pos);
    for (int i = 0; i < pos-1; i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
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