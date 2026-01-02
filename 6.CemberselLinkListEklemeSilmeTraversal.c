#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;

    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* curr = *head;
    struct Node* prev = NULL;

    do {
        if (curr->data == key) {
            if (curr == *head && curr->next == *head) {
                free(curr);
                *head = NULL;
                return;
            }

            if (curr == *head) {
                struct Node* last = *head;
                while (last->next != *head)
                    last = last->next;

                *head = curr->next;
                last->next = *head;
                free(curr);
                return;
            }

            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
}

void traverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head = createNode(10);
    insertAfter(head, 10, 20);
    insertAfter(head, 20, 30);

    deleteNode(&head, 20);
    traverse(head);

    return 0;
}

