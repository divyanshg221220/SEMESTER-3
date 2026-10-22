// Implement the heap data structure using array along with its operations like creation, insertion, deletion and display.
#include <stdio.h>
#include <stdlib.h>
#define size 100
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
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
void heapifyUp(int arr[], int n, int i)
{
	int parent = (i - 1) / 2;
	if (arr[i] > arr[parent])
	{
		swap(&arr[i], &arr[parent]);
		heapifyUp(arr, n, parent);
	}
}
void heapifyDown(int arr[], int n, int i)
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
		swap(&arr[i], &arr[largest]);
		heapifyDown(arr, n, largest);
	}
}
void createHeap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
}
void insertHeap(int arr[], int *n, int key)
{
	if (*n >= size)
	{
		printf("HEAP FULL\n");
		return;
	}
	arr[*n] = key;
	heapifyUp(arr, *n, *n);
	(*n)++;
}
void deleteHeap(int arr[], int *n, int key)
{
	int i;
	for (i = 0; i < *n; i++)
	{
		if (arr[i] == key)
		{
			break;
		}
	}
	if (i == *n)
	{
		printf("ELEMENT NOT FOUND\n");
		return;
	}
	arr[i] = arr[*n - 1];
	(*n)--;
	if (i < *n)
	{
		heapifyUp(arr, *n, i);
		heapifyDown(arr, *n, i);
	}
}
void displayHeap(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
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
	int key;
	createHeap(arr, n);
	printf("Heap created: ");
	displayHeap(arr, n);
	printf("Enter the key to insert: ");
	scanf("%d", &key);
	insertHeap(arr, &n, key);
	printf("Heap after insertion: ");
	displayHeap(arr, n);
	printf("Enter the key to delete: ");
	scanf("%d", &key);
	deleteHeap(arr, &n, key);
	printf("Heap after deletion: ");
	displayHeap(arr, n);
    return 0;
}