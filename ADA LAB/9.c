#include <stdio.h>
#include <stdlib.h>

int n, count, top;

int dfs(int mat[n][n], int vis[], int track[], int source, int stack[])
{
    vis[source] = 1;
    track[source] = 1;

    for(int i = 0; i < n; i++)
    {
        count++;

        if(mat[source][i] && track[i] && vis[i])
            return 1;

        if(mat[source][i] && !vis[i])
        {
            if(dfs(mat, vis, track, i, stack))
                return 1;
        }
    }

    stack[++top] = source;
    track[source] = 0;

    return 0;
}

void topologicalSort(int mat[n][n])
{
    int vis[n], track[n];
    int stack[n];

    for(int i = 0; i < n; i++)
    {
        vis[i] = 0;
        track[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(mat, vis, track, i, stack);
    }
}

void plotter()
{
    FILE *fb, *fw;

    fb = fopen("TopSortBest.txt", "w");
    fw = fopen("TopSortWorst.txt", "w");

    for(int k = 1; k <= 20; k++)
    {
        n = k;

        int adjMat[n][n];

        /* Best Case : No Edges */

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                adjMat[i][j] = 0;
        }

        count = 0;
        top = -1;

        topologicalSort(adjMat);

        fprintf(fb, "%d\t%d\n", n, count);

        /* Worst Case : Complete DAG */

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j > i)
                    adjMat[i][j] = 1;
                else
                    adjMat[i][j] = 0;
            }
        }

        count = 0;
        top = -1;

        topologicalSort(adjMat);

        fprintf(fw, "%d\t%d\n", n, count);
    }

    fclose(fb);
    fclose(fw);

    printf("Files Generated Successfully\n");
}

int main()
{
    plotter();
    return 0;
}