#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front=-1;
int rear=-1;
int data;

int isFull(){
    return (rear+1) % MAX_SIZE==front;
}
int isEmpty(){
    return front==-1;
}
void enqueue(int data)
{
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    if(front==-1)
   {
     front=0;
   }
   rear=(rear+1) % MAX_SIZE;
   queue[rear]=data;
   printf("Elenet %d inserted\n",data);
}
int dequeue()
{
    if(isEmpty()){
        printf("Queue underflow\n");
        return -1;
    }
    if(front=rear){
        front=rear=-1;
    }
    else{
        front=(front+1) % MAX_SIZE;
    }    
    return data;
}
void display()
{
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:");
    for (int i = front; i != (rear+1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    
    printf("Dequeued element: %d\n", dequeue());

    display();

    return 0;
}