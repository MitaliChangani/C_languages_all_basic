#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the front
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (*head);
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Function to delete the last node
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    if (last->prev != NULL) {
        last->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(last);
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head, int pos) {
    if (pos <= 1 || *head == NULL || (*head)->next == NULL) {
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->prev == NULL) {
        return;
    }
    struct Node* toDelete = current->prev;
    if (toDelete->prev != NULL) {
        toDelete->prev->next = current;
    } else {
        *head = current;
    }
    current->prev = toDelete->prev;
    free(toDelete);
}

// Function to display the doubly linked list
void display(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 50);
    insertAtFront(&head, 60);
    insertAtEnd(&head, 70);
    insertAtEnd(&head, 80);
    display(head);  // Output: 60 <-> 50 <-> 70 <-> 80 <-> NULL

    deleteLastNode(&head);
    display(head);  // Output: 60 <-> 50 <-> 70 <-> NULL

    deleteBeforePosition(&head, 3);
    display(head);  // Output: 60 <-> 70 <-> NULL

    return 0;
}
