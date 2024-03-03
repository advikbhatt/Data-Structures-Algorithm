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

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}
struct node *inorderpredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    else
    {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}
int main()
{
    struct node *p = createnode(3);
    struct node *p1 = createnode(2);
    struct node *p2 = createnode(7);
    struct node *p3 = createnode(1);
    struct node *p5 = createnode(5);

    // Linking the nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p5;

    inordertraversal(p);

    deletenode(p, 5);
    printf("\n");

    inordertraversal(p);

    return 0;
}