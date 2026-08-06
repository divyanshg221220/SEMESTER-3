// Implement the bubble sort using c language
#include <stdio.h>
#define size 100
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
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}