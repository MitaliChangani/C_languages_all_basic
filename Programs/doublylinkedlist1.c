#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the front
void insertAtFront(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    } else {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at the end
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}

// Delete the last node
void deleteLastNode() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) { // Only one node
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        struct Node *lastNode = temp->next;
        temp->next = NULL;
        free(lastNode);
    }
}

// Delete a node before specified position
void deleteBeforeSpecifiedPosition(int position) {
    if (head == NULL || position <= 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 2) { // Delete the first node
        struct Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }

    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    toDelete->next->prev = temp;
    free(toDelete);
}

// Print the list
void printList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, position;

    while (1) {
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete last node\n");
        printf("4. Delete before specified position\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteLastNode();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteBeforeSpecifiedPosition(position);
                break;
            case 5:
                printList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}