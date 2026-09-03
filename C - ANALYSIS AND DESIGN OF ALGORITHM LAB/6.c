// Implement quick sort algorithm using divide and conquer technique
#include <stdio.h>
#define size 100
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = (l - 1);
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}
int main(int argc, char const *argv[])
{
    int n = 0;
    int arr[size];
    printf("ENTER 0 TO EXIT\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter [%d] element: ", i);
        int temp;
        scanf("%d", &temp);
        if (temp == 0)
        {
            break;
        }
        arr[i] = temp;
        n++;
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}