// Implement the insertion sort using c language
#include <stdio.h>
#define size 100
int main(int argc, char const *argv[])
{
    int n = 0;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("ENTER 0 TO EXIT\n");
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
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= 0)
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