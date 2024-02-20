#include <stdio.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k - low] = arr[i];
            i++;
        }
        else
        {
            temp[k - low] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k - low] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k - low] = arr[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}

int main()
{
    int arr[] = {1, 5, 87, 65, 43, 64, 643};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printarr(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printarr(arr, n);

    return 0;
}
