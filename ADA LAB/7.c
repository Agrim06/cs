#include <stdio.h>
#include <stdlib.h>

int n;
int count;
int isCyclic;

void dfs(int mat[n][n], int vis[], int parent, int source, int comp[], int compId)
{
    vis[source] = 1;
    comp[source] = compId;

    for (int i = 0; i < n; i++)
    {
        count++;
        if (mat[source][i])
        {
            if (!vis[i])
            {
                dfs(mat, vis, source, i, comp, compId);
            }
            else if (i != parent)
            {
                isCyclic = 1;
            }
        }
    }
}

void tester()
{
    printf("\n--- DFS CONNECTIVITY & ACYCLICITY TESTER ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adjMat[n][n];
    int vis[n];
    int comp[n];

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjMat[i][j]);
        }
        vis[i] = 0;
        comp[i] = 0;
    }

    count = 0;
    isCyclic = 0;
    int compCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            compCount++;
            dfs(adjMat, vis, -1, i, comp, compCount);
        }
    }

    printf("\n--- RESULTS ---\n");
    if (compCount == 1)
    {
        printf("Graph is CONNECTED.\n");
    }
    else
    {
        printf("Graph is DISCONNECTED with %d connected components:\n", compCount);
        for (int c = 1; c <= compCount; c++)
        {
            printf("  Component %d: ", c);
            for (int i = 0; i < n; i++)
            {
                if (comp[i] == c)
                    printf("%d ", i);
            }
            printf("\n");
        }
    }

    if (isCyclic)
    {
        printf("Graph is CYCLIC (contains at least one cycle).\n");
    }
    else
    {
        printf("Graph is ACYCLIC (tree/forest).\n");
    }

    printf("Operation count = %d\n", count);
}

void plotter()
{
    FILE *f1, *f2;

    f1 = fopen("DFSbest.txt", "w");
    f2 = fopen("DFSworst.txt", "w");

    for (int k = 1; k <= 10; k++)
    {
        n = k;

        int adjMat[n][n];
        int vis[n];
        int comp[n];

        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            comp[i] = 0;

            for (int j = 0; j < n; j++)
                adjMat[i][j] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            adjMat[i][i + 1] = 1;
            adjMat[i + 1][i] = 1;
        }

        count = 0;
        isCyclic = 0;
        int compCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                compCount++;
                dfs(adjMat, vis, -1, i, comp, compCount);
            }
        }
        fprintf(f1, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            comp[i] = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    adjMat[i][j] = 1;
                else
                    adjMat[i][j] = 0;
            }
        }

        count = 0;
        isCyclic = 0;
        compCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                compCount++;
                dfs(adjMat, vis, -1, i, comp, compCount);
            }
        }
        fprintf(f2, "%d\t%d\n", n, count);
    }

    fclose(f1);
    fclose(f2);

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