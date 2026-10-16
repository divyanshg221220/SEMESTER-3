// Implement the longest common subsequence problem and calculate its length using dynamic programming approach.
#include <stdio.h>
#include <string.h>
#define size 100
int dp[size][size];
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int longestCommonSubsequence(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (X[m - 1] == Y[n - 1])
    {
        return dp[m][n] = 1 + longestCommonSubsequence(X, Y, m - 1, n - 1);
    }
    else
    {
        return dp[m][n] = max(longestCommonSubsequence(X, Y, m, n - 1), longestCommonSubsequence(X, Y, m - 1, n));
    }
}
int main(int argc, char const *argv[])
{
    char X[size], Y[size];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    printf("Longest common subsequence: %d\n", longestCommonSubsequence(X, Y, m, n));
    return 0;
}