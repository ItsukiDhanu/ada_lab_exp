#include <stdio.h>

#define MAX 100

void dfs(int v, int n, int graph[MAX][MAX], int visited[MAX], int order[MAX], int *top)
{
	visited[v] = 1;
	for (int i = 0; i < n; i++)
		if (graph[v][i] && !visited[i])
			dfs(i, n, graph, visited, order, top);
	order[++(*top)] = v;
}

int main(void)
{
	int n, graph[MAX][MAX] = {0}, visited[MAX] = {0}, order[MAX], top = -1;

	printf("Enter the number of vertices: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix (rows of 0/1):\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(i, n, graph, visited, order, &top);

	printf("Topological Sort Order:\n");
	while (top >= 0)
		printf("%d ", order[top--]);
	printf("\n");
	return 0;
}
