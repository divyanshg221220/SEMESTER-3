// Implement the fractional knapsack problem using greedy approach.
#include <stdio.h>
#include <stdlib.h>
#define size 100
int compare(const void *a, const void *b)
{
    const float *itemA = (const float *)a;
    const float *itemB = (const float *)b;
    float ratioA = itemA[0] / itemA[1];
    float ratioB = itemB[0] / itemB[1];
    if (ratioA < ratioB)
    {
        return 1;
    }
    if (ratioA > ratioB)
    {
        return -1;
    }
    return 0;
}
float knapsack(int W, float weight[], float values[], int n)
{
    float items[n][2];
    for (int i = 0; i < n; i++)
    {
        items[i][0] = values[i];
        items[i][1] = weight[i];
    }
    qsort(items, n, sizeof(items[0]), compare);
    float result = 0.0;
    float currentCapacity = W;
    for (int i = 0; i < n; i++)
    {
        if (items[i][1] <= currentCapacity)
        {
            result += items[i][0];
            currentCapacity -= items[i][1];
        }
        else
        {
            result += (items[i][0] / items[i][1]) * currentCapacity;
            break;
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int n = 0, W;
    float values[size], weight[size];
    printf("ENTER 0 AND 0 TO EXIT\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter [%d] value: ", i + 1);
        float temp1;
        scanf("%f", &temp1);
        printf("Enter [%d] weight: ", i + 1);
        float temp2;
        scanf("%f", &temp2);
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
    printf("Fractional knapsack: %.2f\n", knapsack(W, weight, values, n));
    return 0;
}