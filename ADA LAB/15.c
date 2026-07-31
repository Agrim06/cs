#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, count;

void dijkstra(int cost[n][n], int src, int printDist)
{
    int dist[n], visited[n];
    count = 0;

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX, u = -1;

        for (int j = 0; j < n; j++)
        {
            count++;
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            count++;
            if (!visited[v] && cost[u][v] != INT_MAX && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    if (printDist)
    {
        printf("\nShortest path distances from source vertex %d:\n", src);
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INT_MAX)
                printf("Vertex %d : INF\n", i);
            else
                printf("Vertex %d : %d\n", i, dist[i]);
        }
    }
}

void tester()
{
    printf("\n--- DIJKSTRA'S ALGORITHM TESTER ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], src;
    printf("Enter cost matrix (%dx%d) [Use -1 for infinity]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1) cost[i][j] = INT_MAX;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(cost, src, 1);
    printf("Operation Count = %d\n", count);
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("dijkstra.txt", "w");

    for (int k = 2; k <= 12; k++)
    {
        n = k;
        int cost[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) cost[i][j] = 0;
                else cost[i][j] = rand() % 100 + 1;
            }
        }

        dijkstra(cost, 0, 0);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
    printf("Data generated in dijkstra.txt\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Tester\n2. Plotter\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) tester();
        else if (choice == 2) plotter();
        else printf("Invalid choice!\n");
    }
    return 0;
}