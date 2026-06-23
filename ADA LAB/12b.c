#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, count, dist[100][100];

int floyds(int adjMat[n][n], int n)
{
    count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adjMat[i][j] == -1)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = adjMat[i][j];
                
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

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("floydes.txt", "w");
    for (int k = 2; k < 12; k++)
    {
        n = k;
        int adjMat[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    adjMat[i][j] = rand();
                else
                    adjMat[i][j] = 0;
        floyds(adjMat, n);
        fprintf(fp, "%d\t%d\n", n, count);
    }
    fclose(fp);
}

void main()
{
    plotter();
}