#include <stdio.h>
#include <stdlib.h>

int isCycle = 0, components = 0, n, opcount = 0, isTester;

void bfs(int mat[n][n], int *vis, int source)
{
    int queue[n], parent[n];
    int rear = -1, front = -1;
    vis[source] = 1;
    queue[++rear] = source;
    parent[rear] = -1;
    while (rear != front)
    {
        int curr = queue[++front];
        int par = parent[front];
        if (isTester)
            printf("%d ", curr);
        for (int i = 0; i < n; i++)
        {
            opcount++;
            if (i != par && mat[curr][i] && vis[i])
                isCycle = 1;
            if (mat[curr][i] && !vis[i])
            {
                queue[++rear] = i;
                parent[rear] = curr;
                vis[i] = 1;
            }
        }
    }
}

void checkConnectivity(int mat[n][n])
{
    int vis[n], k = 1;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            components++;
            if (isTester)
                printf("\nConnected component %d: ", k++);
            bfs(mat, &vis[0], i);
        }
    }
}

void plotter()
{
    isTester = 0;
    FILE *f1 = fopen("bfsadjMat.txt", "w");
    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int adjMat[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    adjMat[i][j] = 1;
                }
                else
                {
                    adjMat[i][j] = 0;
                }
            }
        }
        opcount = 0;
        checkConnectivity(adjMat);
        fprintf(f1, "%d\t%d\n", n, opcount);
    }
    fclose(f1);
}

void main()
{
    plotter();
}