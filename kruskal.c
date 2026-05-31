#include <stdio.h>
#define MAX 10

int find_root(int parent[], int v)
{
	while (parent[v] != -1)
		v = parent[v];
	return v;
}

void kruskal(int n, int cost[MAX][MAX])
{
	int parent[MAX], total = 0, edges = 0;

	for (int i = 0; i < n; i++)
		parent[i] = -1;

	while (edges < n - 1)
	{
		int a = -1, b = -1, min = 999;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (cost[i][j] < min)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}

		if (a == -1 || min == 999)
			break;

		cost[a][b] = cost[b][a] = 999;
		if (find_root(parent, a) != find_root(parent, b))
		{
			printf("%d) Minimum edge is: (%d-->%d) and its cost is: %d\n", edges + 1, a, b, min);
			total += min;
			parent[find_root(parent, b)] = find_root(parent, a);
			edges++;
		}
	}

	printf("The minimum spanning tree cost is: %d\n", total);
}

int main(void)
{
	int n, cost[MAX][MAX];

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the cost matrix:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);
	kruskal(n, cost);
	return 0;
}