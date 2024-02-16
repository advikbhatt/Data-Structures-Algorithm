#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int *arr;
    int f;
    int r;
};

int isfull(struct circularqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularqueue *q, int value)
{
    if (isfull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
    }
}
void dequeue(struct circularqueue **q)
{
    int a = -1;
    if (isempty(*q))
    {
        printf("The queue is empty");
    }
    else
    {
        (*q)->f = ((*q)->f + 1) % (*q)->size;
        // free((*q)->arr);
        // a=(*q)->arr[(*q)->f];
    }
    // return a;
}
void queuetraversal(struct circularqueue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%d\n", q->arr[i]);
        }
    }
}

int main()
{
    struct circularqueue *q;
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    if (q->arr == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    if (isempty(q))
    {
        printf("Queue is empty\n");
    }

    enqueue(q, 12);
    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 71);

    queuetraversal(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    queuetraversal(q);

    // This element can be inserted in the circularqueue
    enqueue(q, 56);

    queuetraversal(q);

    return 0;
}
