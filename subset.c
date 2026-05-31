#include <stdio.h>

int set[20], x[20];
int n, target, count = 0;

void subset(int index, int sum)
{
    if(sum == target)
    {
        printf("Solution %d = { ", ++count);

        for(int i = 0; i < n; i++)
            if(x[i] == 1)
                printf("%d ", set[i]);

        printf("}\n");
        return;
    }

    if(index == n || sum > target)
        return;

    x[index] = 1;
    subset(index + 1, sum + set[index]);

    x[index] = 0;
    subset(index + 1, sum);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nPossible subsets are:\n");

    subset(0, 0);

    if(count == 0)
        printf("No subset possible!\n");

    return 0;
}