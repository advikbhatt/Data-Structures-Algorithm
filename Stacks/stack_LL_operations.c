#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top;

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isfull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int peek(int position)
{

    struct node *ptr = top;
    for (int i = 0; (i < position && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int main()
{
    top = push(top, 23);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 7);
    printf("\n");

    traversal(top);

    for (int i = 0; i < 4; i++)
    {
        printf("Value at position %d is %d\n", i, peek(i));
    }

    return 0;
}
