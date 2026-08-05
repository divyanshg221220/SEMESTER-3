// Implement the insertion sort using c language
#include <stdio.h>
#define n 100
int main(int argc, char const *argv[])
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter [%d] element: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && )
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}