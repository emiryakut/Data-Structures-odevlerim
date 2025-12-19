#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
    struct node *prev;
};
struct node *add()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int stop;
    do
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("Please enter a number: ");
        scanf("%d", &new->number);
        if (head == NULL)
        {
            head = new;
            temp = head;
            temp->prev = NULL;
            temp->next = NULL;
        }
        else
        {
            temp->next = new;
            new->prev = temp;
            new->next = NULL;
            temp = new;
        }
        printf("press 0 to stop: ");
        scanf("%d", &stop);
    } while (stop != 0);

    return head;
}
void bubbleSort(struct node *head)
{
    int tempsayi;
    struct node *i, *j;

    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = head; j->next != NULL; j = j->next)
        {
            if (j->number > j->next->number)
            {
                tempsayi = j->number;
                j->number = j->next->number;
                j->next->number = tempsayi;
            }
        }
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->number);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = add();
    bubbleSort(head);
    return 0;
}
