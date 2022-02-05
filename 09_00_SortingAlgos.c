#include<stdio.h>
#include<stdlib.h>

static int n,size;
void printarr(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);


int main()
{
	printf("\nEnter the size of array : ");
	scanf("%d", &size);
	int i,choice,arr[size];
	system("color A");
	do
	{
		line:
		printf("\xB2\xB2\xB2\xB2 Welcome to the sorting of array menu \xB2\xB2\xB2\xB2\n");
		printf("\n1.Merge sort");
		printf("\n2.Quick sort");
		printf("\n3.Radix sort");
		printf("\n4.Heap sort");
		printf("\n0.Exit");
		
		printf("\n\nEnter your choice (0-4) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				makearr();
				printf("\nUnsorted array: \n");
				printarr(arr, size);
				n = sizeof(arr) / sizeof(arr[0]);
				mergeSort(arr, 0, n - 1);
			
				printf("Sorted array: \n");
				printarr(arr, n);
				goto line;
			case 2:
				printf("hello");
				system("pause");
			case 3:
				system("pause");
				printf("hello");
			case 4:
				system("pause");
				printf("hello");
			case 0:
				exit(0);
				break;
			default:
				printf("\n\nInvalid Input\n\n");
				goto line;	
		}
	}while(choice!=0);
}


int makearr()
{

	int i,arr[size];
	for(i=0;i<size;i++)
	{
		printf("\nEnter the value of %d Number : ", i + 1);
		scanf("%d", &arr[i]);	
	}
}


void printarr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


//Merge Sort
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// m is the point where the array is divided into two subarrays
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		// Merge the sorted subarrays
		merge(arr, l, m, r);
	}
}



void merge(int arr[], int p, int q, int r)
{
	// Create L ? A[p..q] and M ? A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];
	int i, j, k;
	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
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

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
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
