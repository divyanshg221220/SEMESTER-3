// Implement the binary search using divide and conquer technique
#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key)
{
    if (high >= low)
    {
        int mid =(low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, low, mid - 1, key);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, key);
        }
    }
    else
    {
        return -1;
    }
}
int main(int argc, char const *argv[])
{
    int n, key;
    printf("Enter number of elements to insert in array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter [%d] element: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
    {
        printf("ELEMENT NOT FOUND\n");
    }
    else
    {
        printf("Element found at index: %d\n", result);
    }
    return 0;
}