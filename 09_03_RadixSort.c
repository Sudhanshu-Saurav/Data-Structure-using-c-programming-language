#include <stdio.h>

void printArray(int arr[], int size);
void radixsort(int arr[], int size);
int getMax(int arr[], int n);
void countingSort(int arr[], int size, int place);

int main()
{
	int i, size;
	printf("\nEnter the size of arr : ");
	scanf("%d", &size);
	int arr[size];
	for (i = 0; i < size; i++)
	{
		printf("\nEnter the value of %d Number : ", i + 1);
		scanf("%d", &arr[i]);
	}
  	printf("\nUnsorted array: \n");
	printArray(arr, size);
  	int n = sizeof(arr) / sizeof(arr[0]);
  	radixsort(arr, n);
  	printf("\nSorted array using Heap sort is : \n");
  	printArray(arr, n);
}


void printArray(int arr[], int size)
{
  	int i;
  	for (i = 0; i < size; ++i)
  	{
    	printf("%d  ", arr[i]);
  	}
  	printf("\n");
}


void radixsort(int arr[], int size)
{
  	int max = getMax(arr, size), place;
	for (place = 1; max / place > 0; place *= 10)
    	countingSort(arr, size, place);
}


int getMax(int arr[], int n)
{
  	int max = arr[0], i;
  	for (i = 1; i < n; i++)
	{
    	if (arr[i] > max)
      		max = arr[i];
	}
  	return max;
}


void countingSort(int arr[], int size, int place)
{
  	int output[size + 1], i;
  	int max = (arr[0] / place) % 10;
	for (i = 1; i < size; i++)
  	{
    	if (((arr[i] / place) % 10) > max)
      		max = arr[i];
  	}
	
	int count[max + 1];
	for (i = 0; i < max; ++i)
    	count[i] = 0;
	for (i = 0; i < size; i++)
    	count[(arr[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
    	count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
  	{
    	output[count[(arr[i] / place) % 10] - 1] = arr[i];
    	count[(arr[i] / place) % 10]--;
  	}
	for (i = 0; i < size; i++)
    	arr[i] = output[i];
}


