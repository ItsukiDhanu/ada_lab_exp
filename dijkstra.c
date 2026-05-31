#include <stdio.h>

#define MAX 10
#define INF 99999

void dijkstra(int cost[MAX][MAX], int n, int source, int dist[MAX], int parent[MAX])
{
	int visited[MAX] = {0};

	for (int i = 0; i < n; i++)
	{
		dist[i] = cost[source][i];
		parent[i] = (i != source && cost[source][i] < INF) ? source : -1;
	}

	dist[source] = 0;
	visited[source] = 1;

	for (int step = 1; step < n; step++)
	{
		int u = -1, best = INF;

		for (int i = 0; i < n; i++)
			if (!visited[i] && dist[i] < best)
				best = dist[u = i];

		if (u == -1)
			break;

		visited[u] = 1;

		for (int v = 0; v < n; v++)
			if (!visited[v] && cost[u][v] < INF && dist[u] + cost[u][v] < dist[v])
			{
				dist[v] = dist[u] + cost[u][v];
				parent[v] = u;
			}
	}
}

void print_paths(int source, int n, int dist[MAX], int parent[MAX])
{
	for (int v = 0; v < n; v++)
	{
		if (v == source)
			continue;

		if (dist[v] >= INF)
		{
			printf("No path from %d to %d\n", source, v);
			continue;
		}

		int path[MAX], len = 0;
		for (int cur = v; cur != -1; cur = parent[cur])
			path[len++] = cur;

		printf("The shortest distance %d -> %d is: %d\n", source, v, dist[v]);
		printf("The path is:\n");
		for (int i = len - 1; i >= 0; i--)
			printf(i == len - 1 ? "%d" : " -> %d", path[i]);
		printf("\n");
	}
}

int main(void)
{
	int n, source;
	int cost[MAX][MAX], dist[MAX], parent[MAX];

	printf("**** DIJKSTRA'S ALGORITHM ******\n");
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the cost matrix\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[i][j]);

	printf("The entered cost matrix is\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d\t", cost[i][j]);
		printf("\n");
	}

	printf("Enter the source vertex: ");
	scanf("%d", &source);

	dijkstra(cost, n, source, dist, parent);
	print_paths(source, n, dist, parent);
	printf("\n********* *************** *********\n");
	return 0;
}