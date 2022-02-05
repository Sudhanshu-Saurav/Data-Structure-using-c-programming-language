#include <stdio.h>

void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);


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
	printf("\nUnsorted array: \n");
	printArray(arr, size);
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
}


void merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int L[n1], M[n2];
	int i, j, k;
	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];
	
	i = 0;
	j = 0;
	k = p;

	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = M[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = M[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


