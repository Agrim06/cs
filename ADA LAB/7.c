#include <stdio.h>
#include <stdlib.h>

int n;
int count;

void dfs(int mat[n][n], int vis[], int source)
{
    vis[source] = 1;

    for(int i=0;i<n;i++)
    {
        count++;

        if(mat[source][i] && !vis[i])
            dfs(mat,vis,i);
    }
}

void plotter()
{
    FILE *f1,*f2;

    f1=fopen("DFSbest.txt","w");
    f2=fopen("DFSworst.txt","w");

    for(int k=1;k<=10;k++)
    {
        n=k;

        int adjMat[n][n];
        int vis[n];

        for(int i=0;i<n;i++)
            vis[i]=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    adjMat[i][j]=0;
                else
                    adjMat[i][j]=0;
            }
        }

        count=0;

        dfs(adjMat,vis,0);

        fprintf(f1,"%d\t%d\n",n,count);

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

        dfs(adjMat,vis,0);

        fprintf(f2,"%d\t%d\n",n,count);
    }

    fclose(f1);
    fclose(f2);

    printf("Files Generated Successfully\n");
}

int main()
{
    plotter();
    return 0;
}