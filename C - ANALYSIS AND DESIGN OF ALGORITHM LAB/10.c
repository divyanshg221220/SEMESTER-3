// Implement the 0/1 knapsack problem using dynamic programming approach.
#include <stdio.h>
#define size 100
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapsack(int W, int weight[], int values[], int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (weight[n - 1] > W)
    {
        return knapsack(W, weight, values, n - 1);
    }
    else
    {
        return max(values[n - 1] + knapsack(W - weight[n - 1], weight, values, n - 1), knapsack(W, weight, values, n - 1));
    }
}
int main(int argc, char const *argv[])
{
    int n = 0, W;
    int values[size], weight[size];
    printf("ENTER 0 AND 0 TO EXIT\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter [%d] value: ", i);
        int temp1;
        scanf("%d", &temp1);
        printf("Enter [%d] weight: ", i);
        int temp2;
        scanf("%d", &temp2);
        if (temp1 == 0 && temp2 == 0)
        {
            break;
        }
        values[i] = temp1;
        weight[i] = temp2;
        n++;
    }
    printf("Enter the maximum weight of knapsack: ");
    scanf("%d", &W);
    printf("0/1 knapsack: %d\n", knapsack(W, weight, values, n));
    return 0;
}