#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void merge(int a[], int low, int mid, int high)
{
	int left_size = mid - low + 1;
	int right_size = high - mid;
	int left[left_size], right[right_size];

	for (int i = 0; i < left_size; i++)
		left[i] = a[low + i];
	for (int i = 0; i < right_size; i++)
		right[i] = a[mid + 1 + i];

	int i = 0, j = 0, k = low;
	while (i < left_size && j < right_size)
		a[k++] = left[i] <= right[j] ? left[i++] : right[j++];
	while (i < left_size)
		a[k++] = left[i++];
	while (j < right_size)
		a[k++] = right[j++];
}

void mergesort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main(void)
{
	int n;
	int a[MAX];
	printf("Enter the number of elements N to perform MERGE SORT : ");
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 500;
		printf("%d\t", a[i]);
	}
	printf("\n");

	clock_t start = clock();
	mergesort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	clock_t end = clock();
	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // in milliseconds
	printf("\nTime taken to sort %d elements: %f milliseconds\n", n, time_taken);
	return 0;
}