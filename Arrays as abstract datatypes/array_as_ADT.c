#include <stdio.h>
#include <stdlib.h>

struct myarr
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myarr *a, int tsize, int usize)
{
    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr=(int *) malloc(tsize*sizeof(int) )

    // This same can also be written as
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
void show(struct myarr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf(("%d\n"), (a->ptr)[i]);
    }
}
void setvalue(struct myarr *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myarr marks;
    createarray(&marks, 10, 2);
    setvalue(&marks);
    show(&marks);
    return 0;
}