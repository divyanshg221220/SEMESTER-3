// Implement the longest common subsequence problem and calculate its length using dynamic programming approach.
#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int lcs(char* X, char* Y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (X[m - 1] == Y[n - 1])
    {
        return 1 + lcs(X, Y, m - 1, n - 1);
    }
    else
    {
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
    }
}
int main(int argc, char const *argv[])
{
    char X[25], Y[25];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    printf("LCS: %d\n", lcs(X, Y, m, n));
    return 0;
}