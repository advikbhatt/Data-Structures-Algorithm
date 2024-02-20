#include <stdio.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {234, 435, 2345, 62, 2, 54, 2, 56, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printarr(arr, n);

    insertionsort(arr, n);

    printarr(arr, n);
    return 0;
}