#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int n, i;
    int a[20000];
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        printf("%d ", a[i]);
    }

    start = clock();
    selectionSort(a, n);
    end = clock();

    printf("\n\nSorted Elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    time_taken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\n\nTime taken = %.3f milliseconds\n", time_taken);
    return 0;
}