#include <stdio.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int n)
{
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {12, 234, 345, 34, 346, 4, 63};
    int n = sizeof(arr) / sizeof(arr[0]);
    printarr(arr, n);

    bubblesort(arr, n);

    printarr(arr, n);

    return 0;
}

// issorted makes the bubble sort adaptive as it reduces the number of pases if the array is already sorted and reduces the time complexity