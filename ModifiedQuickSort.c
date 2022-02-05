#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);//swap function
void printArray(int array[], int size);//For printing the array
void modifiedquickSort(int array[], int low, int high);//modified quick sort funtion
int partition_pivot_median(int array[], int low, int high);//median taken as pivot element
int partition_pivot_first(int array[], int low, int high);//first element of array taken as pivot element
int partition_pivot_last(int array[], int low, int high);//last element of array taken as pivot element
int partition_pivot_random(int array[], int low, int high);//random element taken as pivot

int main() 
{
	int i, n;
	printf("\nEnter the size of array : ");
	scanf("%d", &n);
	int array[n];
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the value of %d Number : ", i + 1);
		scanf("%d", &array[i]);
	}

	int size = sizeof(array) / sizeof(array[0]);
	
  	printf("\nUnsorted Array : \n");
  	printArray(array, size);
 
	modifiedquickSort(array, 0, size - 1);
 
  	printf("\nSorted array : \n");
  	printArray(array, size);
	return 0;
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

void modifiedquickSort(int array[], int low, int high) 
{	
	if (low < high) 
	{
		//int pivot = partition_pivot_first(array, low, high);
		//int pivot = partition_pivot_last(array, low, high);
		//int pivot = partition_pivot_random(array, low, high);
		//int pivot = partition_pivot_median(array, low, high);
 
		// Sort the elements on the left of pivot
		modifiedquickSort(array, low, pivot - 1);
 
		// Sort the elements on the right of pivot
		modifiedquickSort(array, pivot + 1, high);
	}
}

void swap(int *a, int *b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition_pivot_median(int array[], int low, int high) // choosing the median element as pivot 
{
	int pivot;
	int mid = (low + high) / 2;
	if (array[mid] < array[low]) 
		swap(&array[mid], &array[low]);
	if (array[high] < array[low])
		swap(&array[high], &array[low]);
	if (array[high] < array[mid])
		swap(&array[high], &array[mid]);
	swap(&array[mid], &array[high-1]);
//	printf("\n\nEvery Element after passing median function : \n");
 //	printArray(array, 5);
  	pivot = array[high-1];
	return partition_pivot_last(array, low, high);
}

int partition_pivot_first(int array[], int low, int high) //choosing the first element as pivot
{
	int pivot = array[low];
	int i = (low + 1);
 	int j;
	for (j = low + 1; j <= high; j++) 
	{
		if (array[j] < pivot) 
		{
			if (j != i) 
			{
				swap(&array[i], &array[j]);
			}
			i++;
		}
	}
	swap(&array[i - 1], &array[low]);
//	printf("\n\nEvery Element after passing first function : \n");
//  	printArray(array, 5);	
	return (i - 1);
}

int partition_pivot_last(int array[], int low, int high) //choosing the last element as pivot
{
	int pivot = array[high];
	int i = (low - 1);
 	int j;
	for (j = low; j < high; j++) 
	{
		if (array[j] < pivot) 
		{
			swap(&array[++i], &array[j]);
		}
	}
 
	swap(&array[i + 1], &array[high]);
	printf("\n\nEvery Element after passing last function : \n");
 	printArray(array, 5);
	return (i + 1);
}
 
int partition_pivot_random(int array[], int low, int high) 
{
	int pivot;
	int n = rand();
	pivot = low + n % (high - low + 1); // Randomizing the pivot
	return partition_pivot_last(array, low, high);
}



