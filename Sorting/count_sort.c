#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countsort(int *arr, int n)
{
    int i, j;
    int max = maximum(arr, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    i = 0;
    j = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            arr[i++] = j;
            count[j]--;
        }
        else
        {
            j++;
        }
    }

    free(count);
}

int main()
{
    int arr[] = {23, 343, 346, 3456, 34, 573, 345};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printarr(arr, n);

    countsort(arr, n);

    printf("Sorted array: ");
    printarr(arr, n);

    return 0;
}
