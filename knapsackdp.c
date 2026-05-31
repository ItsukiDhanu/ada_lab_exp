#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int main()
{
    int n, m, i, j;
    printf("----- 0/1 Knapsack Problem -----\n");
    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n + 1], p[n + 1];
    printf("Enter weights:\n");
    for (i = 1; i <= n; i++) scanf("%d", &w[i]);

    printf("Enter profits:\n");
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    int dp[n + 1][m + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - w[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("\nDP Table:\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
            printf("%3d ", dp[i][j]);
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", dp[n][m]);
    printf("Selected items: ");
    j = m;
    for (i = n; i > 0; i--)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            printf("%d ", i);
            j = j - w[i];
        }
    }

    printf("\n");
    return 0;
}