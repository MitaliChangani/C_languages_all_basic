#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    int data = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return data;
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

int isEmpty() {
    return top == NULL;
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}