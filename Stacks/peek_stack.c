#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        printf("Stack Overflow cannot push %d into the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int peek(struct stack *sp, int i)
{
    int arrayind = sp->top - i + 1;
    if (arrayind < 0)
    {
        printf("Not a valid position in the stack");
        return -1;
    }
    else
    {
        return sp->arr[arrayind];
    }
}

int main()
{

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 20);
    push(sp, 28);
    push(sp, 78);
    push(sp, 208);
    push(sp, 48);
    push(sp, 2);
    push(sp, 24);
    for (int i = 1; i <= sp->top; i++)
    {
        printf("The value at position %d is %d\n", i, peek(sp, i));
    }

    return 0;
}