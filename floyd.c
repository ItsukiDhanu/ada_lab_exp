#include <stdio.h>
int min(int x, int y) { return x < y ? x : y; }

void floyd(int n, int a[10][10])
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main(void)
{
	int n, a[10][10];

	printf("Enter the number of vertices: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	printf("Entered adjacency matrix is:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}

	floyd(n, a);

	printf("All pair shortest path matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}

	return 0;
}