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

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *searchiterative(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    // struct node *n = search(p, 2);
    // if (n != NULL)
    // {
    //     printf("FOUND : %d", n->data);
    // }
    // else
    // {
    //     printf("ELEMENT NOT FOUND");
    // }

    struct node *n = searchiterative(p, 2);
    if (n != NULL)
    {
        printf("FOUND : %d", n->data);
    }
    else
    {
        printf("ELEMENT NOT FOUND");
    }

    return 0;
}