#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct Queue{
    int item[SIZE];
    int front,rear;
};

void initialize(struct Queue *q){
    q->front=-1;
    q->rear=-1;
}

int isEmpty(struct Queue *q){
    return(q->front==-1);
}

int isFull(struct Queue *q){
    return (q->rear==SIZE-1);
}

void enqueue(struct Queue *q,int value){
    if (isFull(q)){
        printf("Queue is full.Cannot enqueue %d\n",value);
        return;
    }
    if (q->front==-1)
    {
        q->front=0;
    }
    q->rear++;
    q->item[q->rear]=value;
    printf("Inserted: %d\n",value);  
}

int dequeue(struct Queue *q){
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int value=q->item[q->front];
    q->front++;

    if (q->front>q->rear)
    {
        q->front=q->rear=-1;
    }
    return value;
}

void display(struct Queue *q){
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ",q->item[i]);
    }
    printf("\n");    
};

int main(){
    struct Queue q;
    initialize(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q,50);
    display(&q);
    return 0;
}






