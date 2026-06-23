#include <stdio.h>
#include <stdlib.h>

int n;
int count;

void bfs(int mat[n][n], int vis[], int source)
{
    int queue[n];
    int front = 0;
    int rear = 0;

    vis[source] = 1;
    queue[rear++] = source;

    while(front < rear)
    {
        int curr = queue[front++];

        for(int i=0;i<n;i++)
        {
            count++;

            if(mat[curr][i] && !vis[i])
            {
                vis[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void plotter()
{
    FILE *fb,*fw;

    fb = fopen("BFSbest.txt","w");
    fw = fopen("BFSworst.txt","w");

    for(int k=1;k<=10;k++)
    {
        n = k;

        int adjMat[n][n];
        int vis[n];

        for(int i=0;i<n;i++)
            vis[i]=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                adjMat[i][j]=0;
        }

        count=0;

        bfs(adjMat,vis,0);

        fprintf(fb,"%d\t%d\n",n,count);

        for(int i=0;i<n;i++)
            vis[i]=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                    adjMat[i][j]=1;
                else
                    adjMat[i][j]=0;
            }
        }

        count=0;

        bfs(adjMat,vis,0);

        fprintf(fw,"%d\t%d\n",n,count);
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