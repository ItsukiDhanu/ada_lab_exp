#include <stdio.h>
#define MAX 10
#define INF 999

void dijkstra(int cost[MAX][MAX], int n, int source)
{
    int dist[MAX], visited[MAX], path[MAX];
    int i, j, min, u;

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
        path[i] = source;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
            if(visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for(j = 0; j < n; j++)
            if(visited[j] == 0 && (dist[u] + cost[u][j] < dist[j]))
            {
                dist[j] = dist[u] + cost[u][j];
                path[j] = u;
            }
    }

    printf("\nShortest Paths:\n");

    for(i = 0; i < n; i++)
        if(i != source)
        {
            printf("%d -> %d = %d\n", source, i, dist[i]);
        }
}

int main()
{
    int n, source;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(cost, n, source);

    return 0;
}