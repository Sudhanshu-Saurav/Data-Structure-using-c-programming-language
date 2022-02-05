#include <stdio.h>

void printArray(int array[], int size);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *a, int *b);

int main()
{	
	int i, size;
	printf("\nEnter the size of array : ");
	scanf("%d", &size);
	int arr[size];
	for (i = 0; i < size; i++)
	{
		printf("\nEnter the value of %d Number : ", i + 1);
		scanf("%d", &arr[i]);
	}
  	int n = sizeof(arr) / sizeof(arr[0]);

  	printf("Unsorted Array\n");
  	printArray(arr, n);
 	quickSort(arr, 0, n - 1);

  	printf("Sorted array in ascending order: \n");
  	printArray(arr, n);
}


void printArray(int array[], int size)
{
  	int i;
  	for (i = 0; i < size; ++i)
  	{
    	printf("%d  ", array[i]);
  	}
  	printf("\n");
}


void quickSort(int array[], int low, int high)
{
	if (low < high)
  	{
    	int pivot = partition(array, low, high);
    	quickSort(array, low, pivot - 1);
    	quickSort(array, pivot + 1, high);
  	}
}


int partition(int array[], int low, int high)
{
  	int pivot = array[high];
  	int i = (low - 1);
  	int j;
  	for (j = low; j < high; j++)
  	{
    	if (array[j] <= pivot)
    	{
      		i++;
      		swap(&array[i], &array[j]);
    	}
  	}
  	swap(&array[i + 1], &array[high]);
  	return (i + 1);
}


void swap(int *a, int *b)
{
  	int t = *a;
  	*a = *b;
  	*b = t;
}


