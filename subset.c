#include <stdio.h>

int set[20], subset[20];
int n, target, count = 0;

// Function to find subsets
void subsetSum(int index, int currentSum)
{
    // If target is reached
    if (currentSum == target)
    {
        count++;

        printf("Solution %d = { ", count);

        for (int i = 0; i < n; i++)
        {
            if (subset[i] == 1)
                printf("%d ", set[i]);
        }

        printf("}\n");
        return;
    }

    // If sum exceeds target or all elements checked
    if (index == n || currentSum > target)
        return;

    // Include current element
    subset[index] = 1;
    subsetSum(index + 1, currentSum + set[index]);

    // Exclude current element
    subset[index] = 0;
    subsetSum(index + 1, currentSum);
}

int main()
{
    printf("----- Subset Sum Problem -----\n");

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input set elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    // Input target sum
    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nPossible subsets are:\n");

    // Start recursion
    subsetSum(0, 0);

    // If no subset found
    if (count == 0)
        printf("No subset possible!\n");

    return 0;
} 