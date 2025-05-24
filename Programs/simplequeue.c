#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void Insert(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = item;
}

// Function to delete an element from the queue
void Delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front++]);
}

// Function to display elements of the queue
void Display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                Insert(item);
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
