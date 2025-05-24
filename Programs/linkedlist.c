#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

// Function to insert a node before a specified position
void insertBeforePosition(struct Node** last, int data, int pos) {
    if (*last == NULL || pos == 1) {
        printf("Invalid position or empty list.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = (*last)->next;
    for (int i = 1; i < pos - 1 && temp != *last; i++) {
        temp = temp->next;
    }
    if (temp == *last && pos != 2) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the circular linked list
void deleteFirstNode(struct Node** last) {
    if (*last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = (*last)->next;
    if (*last == temp) {
        *last = NULL;
    } else {
        (*last)->next = temp->next;
    }
    free(temp);
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** last, int pos) {
    if (*last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = (*last)->next;
    for (int i = 1; i < pos && temp != *last; i++) {
        temp = temp->next;
    }
    if (temp == *last) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == *last) {
        *last = temp;
    }
    free(delNode);
}

// Function to display the circular linked list
void displayList(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("HEAD\n");
}

int main() {
    struct Node* last = NULL;

    insertAtEnd(&last, 10);
    insertAtEnd(&last, 20);
    insertAtEnd(&last, 30);
    displayList(last);

    insertBeforePosition(&last, 15, 2);
    displayList(last);

    deleteFirstNode(&last);
    displayList(last);

    deleteAfterPosition(&last, 2);
    displayList(last);

    return 0;
}
