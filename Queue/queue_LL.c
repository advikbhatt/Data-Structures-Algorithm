#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void enqueue(struct node **f, struct node **r, int value)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = value;
        n->next = NULL;
        if (*f == NULL)
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
}

int dequeue(struct node **f)
{
    int val = -1;
    if (*f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *ptr = *f;
        *f = ptr->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

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
    struct node *f = NULL;
    struct node *r = NULL;

    dequeue(&f);

    enqueue(&f, &r, 23);
    enqueue(&f, &r, 65);
    enqueue(&f, &r, 3);

    traversal(f);

    dequeue(&f);

    traversal(f);

    return 0;
}
