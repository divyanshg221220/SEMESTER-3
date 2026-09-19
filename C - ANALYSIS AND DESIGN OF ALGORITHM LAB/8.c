// Implement the heap sort using the concept of max heap.
#include <stdio.h>
#define size 100
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	}
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}
int main(int argc, char const *argv[])
{
	int arr[size];
	int n = 0;
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
	heapSort(arr, n);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}