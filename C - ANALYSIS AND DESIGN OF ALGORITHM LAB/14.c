// Implement the minimum cost spanning tree problem using prim's algorithm.
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define size 5
int minweight(int weight[], bool visited[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++) {
        if (visited[v] == false && weight[v] < min) {
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}
int printMST(int parent[], int graph[size][size])
{
    int totalCost = 0;
    printf("MST for the graph:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < size; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    return totalCost;
}
int primMST(int graph[size][size])
{
    int parent[size];
    int weight[size];
    bool visited[size];
    for (int i = 0; i < size; i++) {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    weight[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < size - 1; count++) {
        int u = minweight(weight, visited);
        visited[u] = true;
        for (int v = 0; v < size; v++) {
            if (graph[u][v] && visited[v] == false && graph[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    return printMST(parent, graph);
}
int main(int argc, char const *argv[])
{
    int graph[size][size];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter weight for edge (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("MST: %d\n", primMST(graph));
    return 0;
}