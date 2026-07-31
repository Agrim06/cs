#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, count;

void prims(int cost[n][n], int printMST)
{
    int visited[n];
    int mincost = 0, edges = 0;

    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[0] = 1;
    count = 0;

    if (printMST) printf("\nMinimum Spanning Tree Edges:\n");

    while (edges < n - 1)
    {
        int min = INT_MAX, a = -1, b = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    count++;
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1)
        {
            visited[b] = 1;
            mincost += min;
            edges++;
            if (printMST)
                printf("Edge %d - %d : Cost = %d\n", a, b, min);
        }
        else
        {
            if (printMST) printf("Graph is disconnected! Spanning tree not possible.\n");
            return;
        }
    }

    if (printMST)
        printf("Total Minimum Spanning Tree Cost = %d\n", mincost);
}

void tester()
{
    printf("\n--- PRIM'S ALGORITHM TESTER ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost matrix (%dx%d) [Use 9999 for infinity]:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    prims(cost, 1);
    printf("Operation Count = %d\n", count);
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("prims.txt", "w");

    for (int k = 2; k <= 12; k++)
    {
        n = k;
        int cost[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) cost[i][j] = 9999;
                else cost[i][j] = rand() % 100 + 1;
            }
        }

        prims(cost, 0);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
    printf("Data generated in prims.txt\n");
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