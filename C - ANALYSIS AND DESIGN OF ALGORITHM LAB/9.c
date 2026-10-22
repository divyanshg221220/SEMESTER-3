// Implement the matrix chain multiplication problem parenthesization problem using dynamic programming approach and calculate 
// 1. Optimal number of multiplication.
// 2. Optimal way of parenthesization.
#include <stdio.h>
#include <limits.h>
#define size 100
int dp1[size][size];
int dp2[size][size];
int matrixChainMultiplication(int p[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp1[i][j] != -1)
    {
        return dp1[i][j];
    }
    dp1[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp1[i][j] = (dp1[i][j] < (matrixChainMultiplication(p, i, k) + matrixChainMultiplication(p, k + 1, j) + p[i - 1] * p[k] * p[j])) ? dp1[i][j] : (matrixChainMultiplication(p, i, k) + matrixChainMultiplication(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
        if (dp1[i][j] == matrixChainMultiplication(p, i, k) + matrixChainMultiplication(p, k + 1, j) + p[i - 1] * p[k] * p[j])
        {
            dp2[i][j] = k;
        }
    }
    return dp1[i][j];
}
int matrixChainOrder(int p[], int n)
{
    int i = 1, j = n - 1;
    return matrixChainMultiplication(p, i, j);
}
void matrixChainOrderRec(int i, int j)
{
    if (i == j)
    {
        printf(" M%d ", i);
        return;
    }
    printf("(");
    matrixChainOrderRec(i, dp2[i][j]);
    matrixChainOrderRec(dp2[i][j] + 1, j);
    printf(")");
}
int main(int argc, char const *argv[])
{
    int n = 0;
    int arr[size];
    printf("ENTER 0 AND 0 TO EXIT\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter [%d] row: ", i + 1);
        int temp1;
        scanf("%d", &temp1);
        printf("Enter [%d] column: ", i + 1);
        int temp2;
        scanf("%d", &temp2);
        if (temp1 == 0 && temp2 == 0)
        {
            break;
        }
        if (n == 0)
        {
            arr[n++] = temp1;
        }
        arr[n++] = temp2;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp1[i][j] = -1;
        }
    }
    printf("Optimal number of multiplication: %d\n", matrixChainOrder(arr, n));
    printf("Optimal way of parenthesization: ");
    matrixChainOrderRec(1, n - 1);
    return 0;
}