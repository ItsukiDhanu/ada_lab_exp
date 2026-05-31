#include <stdio.h>

#define MAX 10
#define INF 9999

void prim(int n, int cost[MAX][MAX])
{
	int parent[MAX], key[MAX], used[MAX] = {0};

	for (int i = 0; i < n; i++)
	{
		key[i] = INF;
		parent[i] = -1;
	}

	key[0] = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1;
		for (int v = 0; v < n; v++)
			if (!used[v] && (u == -1 || key[v] < key[u]))
				u = v;

		if (u == -1) break;
		used[u] = 1;

		for (int v = 0; v < n; v++)
			if (!used[v] && cost[u][v] != 0 && cost[u][v] < key[v])
			{
				key[v] = cost[u][v];
				parent[v] = u;
			}
	}

	int total = 0;
	for (int v = 1; v < n; v++)
	{
		if (parent[v] == -1)
		{
			printf("Spanning tree does not exist\n");
			return;
		}
		total += cost[v][parent[v]];
		printf("%d -- %d (cost %d)\n", parent[v], v, cost[v][parent[v]]);
	}
	printf("Total cost: %d\n", total);
}

int main(void)
{
	int n, cost[MAX][MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);

	prim(n, cost);
	return 0;
}