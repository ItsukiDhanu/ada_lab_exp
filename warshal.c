#include <stdio.h>

#define MAX 10

void warshall(int n, int a[MAX][MAX], int r[MAX][MAX])
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
}

int main(void)
{
	int n, a[MAX][MAX], r[MAX][MAX];

	printf("Enter the number of vertices: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix (%d x %d):\n", n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			r[i][j] = a[i][j];
		}

	warshall(n, a, r);

	printf("Transitive closure:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", r[i][j]);
		printf("\n");
	}

	return 0;
}