#include <stdio.h>
#include <stdlib.h>

int n, count = 0, top = -1;

int dfs(int mat[n][n], int *vis, int *track, int source, int *stack)
{
    vis[source] = 1;
    track[source] = 1;

    for (int i = 0; i < n; i++)
    {
        count++;
        if (mat[source][i] && track[i] && vis[i])
        {
            return 1;
        }

        if (mat[source][i] && !vis[i] && dfs(mat, vis, track, i, stack))
        {
            return 1;
        }
    }

    stack[++top] = source;
    track[source] = 0;
    return 0;
}

int *checkConnectivity(int mat[n][n])
{
    int vis[n], track[n];
    int* stack = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(mat, &vis[0], &track[0], i, stack))
            {
                return NULL;
            }
        }
    }

    return stack;
}

void plotter()
{
    FILE *f1 = fopen("bfsMatTopSort.txt", "w");

    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int adjMat[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                adjMat[i][j] = 1;
            }
        }

        count = 0, top = -1;
        checkConnectivity(adjMat);
        fprintf(f1, "%d\t%d\n", n, count);
    }

    fclose(f1);
}

void main()
{
    plotter();
}
