#include <stdio.h>
#include <stdlib.h>

int n;
int indeg[20];
int queue[20];
int front, rear;
int count;

int bfs(int mat[n][n])
{
    int count = 0;

    front = rear = -1;

    for(int i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
            queue[++rear] = i;
    }

    while(front != rear)
    {
        int curr = queue[++front];

        count++;

        for(int i = 0; i < n; i++)
        {
            count++;

            if(mat[curr][i])
            {
                indeg[i]--;

                if(indeg[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    return count != n;
}

void plotter()
{
    FILE *fb, *fw;

    fb = fopen("SrcRemBest.txt", "w");
    fw = fopen("SrcRemWorst.txt", "w");

    for(int k = 1; k <= 20; k++)
    {
        n = k;

        int adjMat[n][n];

        /* Best Case */

        for(int i = 0; i < n; i++)
            indeg[i] = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                adjMat[i][j] = 0;
        }

        count = 0;

        bfs(adjMat);

        fprintf(fb, "%d\t%d\n", n, count);

        /* Worst Case */

        for(int i = 0; i < n; i++)
            indeg[i] = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                adjMat[i][j] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                adjMat[i][j] = 1;
                indeg[j]++;
            }
        }

        count = 0;

        bfs(adjMat);

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