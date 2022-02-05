#include <stdio.h>

void printArray(int arr[], int n);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);

int main()
{
	int i,size,value;
	printf("\nEnter the size of array : ");
	scanf("%d",&size);
	int arr[size];
	for(i=0;i<size;i++)
	{
		printf("\nEnter the value of %d number : ",i+1);
		scanf("%d",&value);
		arr[i]=value;
	}
	printf("\nUnsorted array: \n");
	printArray(arr, size);
	int n = sizeof(arr) / sizeof(arr[0]);
	
	heapSort(arr, n);
	
	printf("\nSorted array using Heap sort is : \n");
	printArray(arr, n);
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}


void heapSort(int arr[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}	
	for (i = n - 1; i >= 0; i--)
	{
	    swap(&arr[0], &arr[i]);
	    heapify(arr, i, 0);
	}
}


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}
	
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
	    heapify(arr, n, largest);
  	}
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

