#include <stdio.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexofmin])
            {
                indexofmin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexofmin];
        arr[indexofmin] = temp;
    }
}

int main()
{
    int arr[] = {234, 2345, 76, 56, 767, 8, 9, 457};
    int n = sizeof(arr) / sizeof(arr[0]);
    printarr(arr, n);

    selectionsort(arr, n);

    printarr(arr, n);
    return 0;
}