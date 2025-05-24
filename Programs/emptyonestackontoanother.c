#include<stdio.h>
#define SIZE 5
void push(int stack[],int *top, int value){
    if(*top==SIZE -1){
        printf("stack is full! cannot push %d\n",value);
        return ;
    }
    stack[++(*top)]=value;
}
int pop(int stack[],int *pop){
    if(*top ==-1){
        printf("stack is empty\n");
        return -1;
    }
    return stack[(*top)--];
}
