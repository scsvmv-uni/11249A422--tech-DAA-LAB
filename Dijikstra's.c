#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, src;
    int cost[10][10], dist[10], visited[10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with infinity (except diagonal)
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INT_MAX;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    for (i = 0; i < n; i++)
        dist[i] = cost[src][i];

    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra's algorithm
    for (i = 1; i < n; i++)
    {
        int min = INT_MAX, u = -1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // no reachable vertex

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && cost[u][j] != INT_MAX &&
                dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances:\n");
    for (i = 0; i < n; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);

    return 0;
}
