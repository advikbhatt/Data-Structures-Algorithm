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

void postordertraversal(struct node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}

void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}

int main()
{
    struct node *p = createnode(2);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(7);
    struct node *p3 = createnode(72);
    struct node *p4 = createnode(8);
    struct node *p5 = createnode(75);

    // Linking the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    preordertraversal(p);

    printf("\n");

    postordertraversal(p);

    printf("\n");

    inordertraversal(p);

    return 0;
}