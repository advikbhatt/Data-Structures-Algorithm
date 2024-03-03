#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    p->data = data;

    return p;
}

int main()
{

    // struct node * p;
    // p=(struct node *)malloc(sizeof(struct node));
    // p->left=NULL;
    // p->right=NULL;

    // struct node * p1;
    // p1=(struct node *)malloc(sizeof(struct node));
    // p1->left=NULL;
    // p1->right=NULL;

    // struct node * p2;
    // p2=(struct node *)malloc(sizeof(struct node));
    // p2->left=NULL;
    // p2->right=NULL;

    // This can be done simply by
    struct node *p = createnode(2);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(7);

    // Linking the nodes
    p->left = p1;
    p->right = p2;

    return 0;
}