#include <stdio.h>
#include <limits.h>

int n, cost[10][10], visited[10];

// Function to find minimum of two numbers
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// TSP recursive function
int tsp(int city)
{
    int i, min_cost = INT_MAX, temp;

    visited[city] = 1;

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] != 0)
        {
            temp = cost[city][i] + tsp(i);
            min_cost = min(min_cost, temp);
        }
    }

    visited[city] = 0;

    // If all cities visited, return to starting city
    if (min_cost == INT_MAX)
        return cost[city][0];

    return min_cost;
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Minimum tour cost: %d\n", tsp(0));

    return 0;
}
