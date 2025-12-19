#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* Insertion(int array[], int n)
{

    struct node *temp, *new, *head;
    head = NULL;
    temp = NULL;

    for (int i = 0; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = array[i];
        new->next=NULL;
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
    }
    return head;
}
struct node* Deletion(struct node *head,int value){
    struct node *temp = head;
    struct node *prev = NULL;

    if(temp!=NULL && temp->data == value){
        head = temp->next;
        free(temp);
        return head;
    }
    while(temp!=NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Data not found!\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);

    return head;

}
void PrintingTraversel(struct node *head){
    struct node *temp = head;

    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int arrray[4] = {3, 9, 5, 6};
    struct node *head = Insertion(arrray, 4);

    head = Deletion(head,3);    //O(1)
    head = Deletion(head,9);    //O(n)

    PrintingTraversel(head);

}

