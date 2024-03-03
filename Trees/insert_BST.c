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
void insert(struct node * root,int key){
    struct node * prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key=root->data){
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node * new=createnode(key);

    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
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

    insert(p,4);


    struct node *n = searchiterative(p, 4);
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