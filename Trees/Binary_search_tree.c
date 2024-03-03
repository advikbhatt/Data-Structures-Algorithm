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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
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

  
    printf("%d\n",isBST(p));
    

    return 0;
}