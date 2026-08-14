#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, m;
    printf("Enter number of elements to insert in first array: ");
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter [%d] element: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of elements to insert in second array: ");
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        printf("Enter [%d] element: ", i);
        scanf("%d", &arr2[i]);
    }
    int arr[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
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