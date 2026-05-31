#include <stdio.h>

int x[20], n;

int safe(int row, int col)
{
    for(int i = 1; i < row; i++)
        if(x[i] == col || (i - x[i]) == (row - col) || (i + x[i]) == (row + col))
            return 0;
    return 1;
}

void queen(int row)
{
    if(row > n)
    {
        printf("\nSolution:\n");
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                if(x[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            printf("\n");
        }
        return;
    }

    for(int col = 1; col <= n; col++)
        if(safe(row, col))
        {
            x[row] = col;
            queen(row + 1);
        }
}

int main()
{
    printf("Enter value of N: ");
    scanf("%d", &n);
    queen(1);
    return 0;
}