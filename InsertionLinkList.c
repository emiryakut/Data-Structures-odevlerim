#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *Insert(int array[], int count)
{
    struct node *head = NULL;
    struct node *temp = NULL;

    for (int i = 0; i < count; i++)
    {
        if (head == NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = array[i];
            head->next = NULL;
            head->prev = NULL;
            temp = head;
        }
        else
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp->next->data = array[i];
            temp->next->next = NULL;
            temp->next->prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

void yazdir(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

struct node *prev(struct node *head)
{
    struct node *temp = head;
    head->prev = NULL;

    while (temp != NULL)
    {
        if (temp->next != NULL)
            temp->next->prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    int array[] = {5, 9, 4, 6};
    struct node *head = Insert(array, 4);

    head = prev(head);
    yazdir(head);
    return 0;
}
