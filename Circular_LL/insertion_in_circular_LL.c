#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    // One method to do traversal in circualr linekd list,
    // printf("%d\n", ptr->data);
    // ptr = ptr->next;
    // while (ptr != head)
    // {
    //     printf("%d\n", ptr->data);
    //     ptr = ptr->next;
    // }

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct node * insertatfirst(struct node* head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p=head->next;
    ptr->data=data;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
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

    head->data = 10;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 34;
    third->next = head;

    traversal(head);

    head=insertatfirst(head,45);
    traversal(head);

    return 0;
}