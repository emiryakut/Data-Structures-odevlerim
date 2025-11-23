#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

struct node* ekleme() {
    int secim;
    struct node *head = NULL;
    struct node *temp = NULL;

    do {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        printf("Please enter a number: ");
        scanf("%d", &new->number);
        new->next = NULL;

        if (head == NULL) {
            head = new;
            temp = head;
        } else {
            temp->next = new;
            temp = new;
        }

        printf("Press 1 to add an number, press 0 to stop.: ");
        scanf("%d", &secim);

    } while(secim == 1);

    if(temp != NULL)
        temp->next = head;

    return head;
}

void write(struct node *head) {
    if(head == NULL) return;

    struct node *temp = head;
    int count = 1;

    do {
        printf("%d. number: %d\n", count, temp->number);
        temp = temp->next;
        count++;
    } while(temp != head);
}

int main() {
    struct node *head = add();
    write(head);
    return 0;
}
