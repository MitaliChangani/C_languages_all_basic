#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

// Stack implementation
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isEmptyStack(Stack *stack) {
    return stack->top == -1;
}

int isFullStack(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void pushStack(Stack *stack, int data) {
    if (isFullStack(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = data;
}

int popStack(Stack *stack) {
    if (isEmptyStack(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Queue implementation
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmptyQueue(Queue *queue) {
    return queue->front == -1;
}

int isFullQueue(Queue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueueQueue(Queue *queue, int data) {
    if (isFullQueue(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmptyQueue(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = data;
}

int dequeueQueue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return data;
}

// Functions to perform the desired operations
void emptyStack1OntoStack2(Stack *stack1, Stack *stack2) {
    while (!isEmptyStack(stack1)) {
        int data = popStack(stack1);
        pushStack(stack2, data);
    }
}

void queueToStack(Queue *queue, Stack *stack) {
    while (!isEmptyQueue(queue)) {
        int data = dequeueQueue(queue);
        pushStack(stack, data);
    }
}

void reverseQueueUsingStack(Queue *queue) {
    Stack stack;
    initializeStack(&stack);

    // Move all items from queue to stack
    queueToStack(queue, &stack);

    // Move all items from stack back to queue (reversed order)
    while (!isEmptyStack(&stack)) {
        int data = popStack(&stack);
        enqueueQueue(queue, data);
    }
}

int main() {
    Stack stack1, stack2;
    Queue queue;

    // Initialize stacks and queue
    initializeStack(&stack1);
    initializeStack(&stack2);
    initializeQueue(&queue);

    // Push elements onto stack1
    pushStack(&stack1, 10);
    pushStack(&stack1, 20);
    pushStack(&stack1, 30);

    // Enqueue elements into queue
    enqueueQueue(&queue, 40);
    enqueueQueue(&queue, 50);
    enqueueQueue(&queue, 60);

    // Empty stack1 onto stack2
    emptyStack1OntoStack2(&stack1, &stack2);

    // Move items from queue to stack
    queueToStack(&queue, &stack2);

    // Reverse the order of items in the queue
    reverseQueueUsingStack(&queue);

    // Display the resulting stack and queue
    printf("Stack 2 elements: ");
    while (!isEmptyStack(&stack2)) {
        printf("%d ", popStack(&stack2));
    }
    printf("\n");

    printf("Queue elements: ");
    while (!isEmptyQueue(&queue)) {
        printf("%d ", dequeueQueue(&queue));
    }
    printf("\n");

    return 0;
}