#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int *arr;
    int f;
    int r;
};

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct queue *q)
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

void enqueue(struct queue *q, int value)
{
    if (isfull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue **q)
{
    int a = -1;
    if (isempty(*q))
    {
        printf("The queue is empty\n");
    }

    else
    {
        (*q)->f++;
        a = (*q)->arr[(*q)->f];
    }
    return a;
}
void queuetraversal(struct queue *q)
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
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
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

    if (q->arr == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    if (isempty(q))
    {
        printf("Queue is empty\n");
    }

    // This element cannot be inserted in the queue as the front (f) is positioned at the end where it is equal to the rear (r)
    enqueue(q, 56);

    return 0;
}
