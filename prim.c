#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        int min = INF;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++)
            if(visited[i] == 1)
                for(int j = 0; j < n; j++)
                    if(visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }

        printf("%d --> %d = %d\n", a, b, min);

        total += min;
        visited[b] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", total);
    return 0;
}