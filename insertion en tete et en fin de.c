#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;

        newNode->next = *head;
        newNode->prev = tail;

        tail->next = newNode;
        (*head)->prev = newNode;

        *head = newNode;
    }
}
void insertTail(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;

        newNode->next = *head;
        newNode->prev = tail;

        tail->next = newNode;
        (*head)->prev = newNode;
    }

void displayList(Node* head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Node* temp = head;
    printf("Liste : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    Node* head = NULL;

    insertHead(&head, 10);
    insertHead(&head, 20);
    insertTail(&head, 30);
    insertTail(&head, 40);

    displayList(head);

    return 0;
}