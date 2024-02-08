#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    head->prev=NULL;

    second->data = 23;
    second->next = third;
    second->prev=head;

    third->data = 34;
    third->next = NULL;
    third->prev=second;

    traversal(head);

    return 0;
}