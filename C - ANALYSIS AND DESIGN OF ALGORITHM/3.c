// Implement merge procedure by taking two different user input arrays
#include <stdio.h>
#define size 100
int main(int argc, char const *argv[])
{
    int n = 0;
    int arr1[size];
    printf("Enter first array elements\n");
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
        arr1[i] = temp;
        n++;
    }
    printf("\n");
    int m = 0;
    int arr2[size];
    printf("Enter second array elements\n");
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
        arr2[i] = temp;
        m++;
    }
    int arr[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    printf("Merged array: ");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}