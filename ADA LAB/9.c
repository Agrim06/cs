#include <stdio.h>
#include <stdlib.h>

int n, count, top;

int dfs(int mat[n][n], int vis[], int track[], int source, int stack[])
{
    vis[source] = 1;
    track[source] = 1;

    for (int i = 0; i < n; i++)
    {
        count++;

        if (mat[source][i] && track[i] && vis[i])
            return 1;

        if (mat[source][i] && !vis[i])
        {
            if (dfs(mat, vis, track, i, stack))
                return 1;
        }
    }

    stack[++top] = source;
    track[source] = 0;

    return 0;
}

int topologicalSort(int mat[n][n], int stack[])
{
    int vis[n], track[n];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        track[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(mat, vis, track, i, stack))
                return 1; 
        }
    }

    return 0; 
}

void tester()
{
    printf("\n--- TOPOLOGICAL SORT (DFS) TESTER ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int mat[n][n];
    int stack[n];

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    count = 0;
    top = -1;

    int isCyclic = topologicalSort(mat, stack);

    if (isCyclic)
    {
        printf("\nGraph contains a cycle! Topological ordering is not possible.\n");
    }
    else
    {
        printf("\nTopological Sorting Order:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    printf("Operation count = %d\n", count);
}

void plotter()
{
    FILE *fb, *fw;

    fb = fopen("TopSortBest.txt", "w");
    fw = fopen("TopSortWorst.txt", "w");

    for (int k = 1; k <= 20; k++)
    {
        n = k;

        int mat[n][n];
        int stack[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                mat[i][j] = 0;
        }

        for(int i = 0; i < n - 1; i++){
            mat[i][i + 1] = 1;
        }

        count = 0;
        top = -1;

        topologicalSort(mat, stack);

        fprintf(fb, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > i)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }

        count = 0;
        top = -1;

        topologicalSort(mat, stack);

        fprintf(fw, "%d\t%d\n", n, count);
    }

    fclose(fb);
    fclose(fw);

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