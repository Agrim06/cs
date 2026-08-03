#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, count;

void prims(int cost[n][n], int printMST)
{
    int key[n], parent[n], vis[n];
    int minCost = 0;
    count = 0;

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        vis[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            count++;
            if (!vis[j] && key[j] < min)
            {
                min = key[j];
                u = j;
            }
        }

        if (u == -1)
        {
            if (printMST)
                printf("Graph is disconnected!\n");
            return;
        }
        
        vis[u] = 1;

        for (int v = 0; v < n; v++)
        {
            count++;

            if (!vis[v] && cost[u][v] != 9999 && cost[u][v] < key[v])
            {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    if (printMST)
        printf("\nMinimum Spanning Tree Edges:\n");

    for (int i = 1; i < n; i++)
    {
        if (parent[i] != -1)
        {
            minCost += cost[parent[i]][i];

            if (printMST)
                printf("%d - %d : Cost = %d\n", parent[i], i, cost[parent[i]][i]);
        }
    }

    if (printMST)
        printf("Total Minimum Spanning Tree Cost = %d\n", minCost);
}

void tester()
{
    printf("\n--- PRIM'S ALGORITHM TESTER ---\n");

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter the cost matrix (%dx%d)\n", n, n);
    printf("Use 9999 for infinity\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    prims(cost, 1);
    printf("Operation Count = %d\n", count);
}

void plotter()
{
    srand(time(NULL));

    FILE *fp = fopen("prim.txt", "w");

    for (n = 2; n <= 20; n++)
    {
        int cost[n][n];

        for (int i = 0; i < n; i++)
        {
            cost[i][i] = 9999;

            for (int j = i + 1; j < n; j++)
            {
                int w = rand() % 100 + 1;

                cost[i][j] = w;
                cost[j][i] = w;
            }
        }
        prims(cost, 0);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
    printf("Data generated successfully in prims.txt\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Tester\n");
        printf("2. Plotter\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                tester();
                break;

            case 2:
                plotter();
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}