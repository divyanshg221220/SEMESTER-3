// Implement the minimum cost spanning tree problem using kruskal's algorithm.
#include <stdio.h>
#include <stdlib.h>
#define size 5
int comparator(const int p1[], const int p2[])
{
    return p1[2] - p2[2];
}
void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}
void unionSet(int u, int v, int parent[], int rank[], int n)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}
int printMST(int parent[], int edge[][3], int n)
{
    int totalCost = 0;
    printf("MST for the graph:\n");
    printf("Edge \tWeight\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != i) {
            printf("%d - %d \t%d \n", parent[i], i, edge[i][2]);
            totalCost += edge[i][2];
        }
    }
    return totalCost;
}
int kruskalMST(int n, int edge[n][3])
{
    qsort(edge, n, sizeof(edge[0]), comparator);
    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        if (v1 != v2) {
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
        }
    }
    printMST(parent, edge, n);
    return minCost;
}
int main(int argc, char const *argv[])
{
    int edge[size][3];
    printf("Enter the edges matrix for the graph:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for edge [%d] [%d]: ", i, j);
            scanf("%d", &edge[i][j]);
        }
    }
    printf("MST: %d\n", kruskalMST(size, edge));
    return 0;
}