#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *deletehead(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node *deleteatend(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct node *deletewithvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    
    if (p->data == value)
    {
        head = p->next;
        free(p);
        return head;
    }

    while (q != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }

    if (q != NULL)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}


int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth;
    fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth;
    fifth= (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 34;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data=90;
    fifth->next=NULL;

    traversal(head);

    head = deletehead(head);
    traversal(head);

    head = deleteatindex(head, 2);
    traversal(head);

    head = deleteatend(head);
    traversal(head);

// This wil only delete the element if it is present in the linked list if not then it will not delete any item.
    head = deletewithvalue(head,2);         // THIS HAS NO ACTION.
    head = deletewithvalue(head,23);
    traversal(head);

    return 0;
}