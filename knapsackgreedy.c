#include <stdio.h>

int main()
{
    float weight[50], profit[50], ratio[50], Totalvalue = 0.0f, temp, capacity;
    int i, j, num;

    printf("Enter number of items :");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("\n\nEnter Weight and Profit for item[%d] :\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("\n\nEnter capacity of knapsack :\n");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++)
        for (j = i + 1; j < num; j++)
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j]; ratio[j] = ratio[i]; ratio[i] = temp;
                temp = weight[j]; weight[j] = weight[i]; weight[i] = temp;
                temp = profit[j]; profit[j] = profit[i]; profit[i] = temp;
            }

    printf("\nKnapsack Problem using Greedy Method :\n");

    for (i = 0; i < num ; i++)
    {
        if (weight[i] > capacity)
        break;
        else
        {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
    }
    if (i < num)
        Totalvalue += ratio[i] * capacity;

    printf("\nThe maximum value is :%f\n", Totalvalue);
    return 0;
}
