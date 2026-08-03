#include <stdio.h>
#include <stdlib.h>

int n, count, paths[100][100];

void warshall(int mat[n][n], int n)
{
    count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            paths[i][j] = mat[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (paths[i][k])
            {
                for (int j = 0; j < n; j++)
                {
                    count++;
                    paths[i][j] = paths[i][j] || (paths[i][k] && paths[k][j]);
                }
            }
}

void tester()
{
    printf("\n--- WARSHALL'S ALGORITHM TESTER ---\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n > 100)
    {
        printf("Number of vertices cannot exceed 100!\n");
        return;
    }

    int mat[n][n];

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    warshall(mat, n);

    printf("\nTransitive Closure (Path Matrix):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", paths[i][j]);
        }
        printf("\n");
    }

    printf("\nOperation count = %d\n", count);
}

void plotter()
{
    FILE *f1 = fopen("warshallbest.txt", "w");
    FILE *f2 = fopen("warshallworst.txt", "w");

    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int mat[n][n];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;

        for (int i = 0; i < n - 1; i++)
            mat[i][i + 1] = 1;
        mat[n - 1][0] = 1;
        
        warshall(mat, n);
        fprintf(f1, "%d\t%d\n", n, count);

        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                if (i != j)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
        warshall(mat, n);
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