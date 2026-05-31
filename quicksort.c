#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int partition(int a[], int low, int high)
{
	int pivot = a[(low + high) / 2];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
			i++;
		while (a[i] < pivot);
		do
			j--;
		while (a[j] > pivot);

		if (i >= j)
			return j;

		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivotIndex = partition(a, low, high);
		quickSort(a, low, pivotIndex);
		quickSort(a, pivotIndex + 1, high);
	}
}

int main(void)
{
	int n;
	int a[MAX];
	printf("Enter the number of elements N to perform QUICK SORT : ");
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 500;
		printf("%d\t", a[i]);
	}
	printf("\n");

	clock_t start = clock();
	quickSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
	clock_t end = clock();
	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
	printf("\nTime taken to sort %d elements: %f milliseconds\n", n, time_taken);
	return 0;
}