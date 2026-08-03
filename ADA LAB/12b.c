#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, count, dist[100][100];

void floyds(int mat[n][n], int n)
{
    count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == -1)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = mat[i][j];
                
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
        {
            int tempDist = dist[i][k];
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > tempDist)
                {
                    count++;
                    if (dist[k][j] != INT_MAX && dist[i][j] > tempDist + dist[k][j])
                    {
                        dist[i][j] = tempDist + dist[k][j];
                    }
                }
            }
        }
}

void tester()
{
    printf("\n--- FLOYD'S ALGORITHM TESTER ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n > 100)
    {
        printf("Number of vertices cannot exceed 100!\n");
        return;
    }

    int mat[n][n];

    printf("Enter the cost matrix (%dx%d):\n", n, n);
    printf("(Use -1 to represent infinity / no direct edge, and 0 for self-loops)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    floyds(mat, n);

    printf("\nAll-Pairs Shortest Path Matrix (Distance Matrix):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nOperation count = %d\n", count);
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("floydes.txt", "w");
    for (int k = 2; k < 12; k++)
    {
        n = k;
        int mat[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    mat[i][j] = rand() % 100 + 1;
                else
                    mat[i][j] = 0;
        floyds(mat, n);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
    printf("Data files generated successfully!\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Tester\n2. Plotter\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        if (choice == 1)
            tester();
        else if (choice == 2)
            plotter();
        else
            printf("Invalid choice!\n");
    }
    return 0;
}