#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX],top=-1,choice,n,value;
int main(){
    while (1)
    {
        
    
    
    printf("\n1.Push\n 2.Pop\n 3.Display\n 4.exit\n");
    printf("Enter choice: \n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        if (top==MAX-1)
        {
            printf("Stack is full..");
        }
        else{
            printf("Enter how many number do you want to store in stack: ");
            scanf("%d",&n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter Data %d :",i+1);
                scanf("%d",&value);
                top++;
                stack[top]=value;
                printf("%d is instered..\n",value);
            }
            
        }
        break;
    case 2:
        if (top==-1)
        {
            printf("Stack is empty..\n");
        }
        else
        {
            printf("Enter no of element to be poped: ");
            scanf("%d",&n);
            for (int i = 0; i < n; i++)
            {
                value=stack[top];
                top--;
                printf("%d is poped\n",value);
            }
            
        }
        break;
    case 3:
        if (top==-1)
        {
            printf("Stack is empty..\n");
        }
        else{
            for (int i = top; i >=0; i--)
            {
                printf("%d ",stack[i]);
            }
            
        }
        break;
    case 4:
        exit(0);
    default:
        break;
    return 0;
    }
    }
}