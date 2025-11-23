#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
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
        new->next = NULL;

        if (head == NULL)
        {
            head = new;
            temp = head;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        printf("Press 1 to add an number, press 0 to stop.: ");
        scanf("%d", &stop);

    } while (stop != 0);
    return head;
}
void write(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    write(head->next);
    printf("%d\n",head->number);


}
int main()
{
    struct node *head = add();
    write(head);
}
