// Implement the job sequencing problem using greedy approach.
#include <stdio.h>
#include <stdlib.h>
#define size 100
int compare(const void *a, const void *b)
{
    const int *jobA = (const int *)a;
    const int *jobB = (const int *)b;
    if (jobA[1] < jobB[1])
    {
        return 1;
    }
    if (jobA[1] > jobB[1])
    {
        return -1;
    }
    return 0;
}
int jobSequencing(int deadline[], int profit[], int n)
{
    int jobs[n][2];
    for (int i = 0; i < n; i++)
    {
        jobs[i][0] = deadline[i];
        jobs[i][1] = profit[i];
    }
    qsort(jobs, n, sizeof(jobs[0]), compare);
    int totalProfit = 0;
    int slot[n];
    for (int i = 0; i < n; i++)
    {
        slot[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int start = jobs[i][0] < n ? jobs[i][0] : n;
        for (int j = start - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += jobs[i][1];
                break;
            }
        }
    }
    return totalProfit;
}
int main(int argc, char const *argv[])
{
    int n = 0;
    int deadline[size], profit[size];
    printf("ENTER 0 AND 0 TO EXIT\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter [%d] deadline: ", i + 1);
        int temp1;
        scanf("%d", &temp1);
        printf("Enter [%d] profit: ", i + 1);
        int temp2;
        scanf("%d", &temp2);
        if (temp1 == 0 && temp2 == 0)
            break;
        deadline[i] = temp1;
        profit[i] = temp2;
        n++;
    }
    printf("Job sequencing: %d", jobSequencing(deadline, profit, n));
    return 0;
}