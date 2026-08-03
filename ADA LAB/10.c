#include <stdio.h>
#include <stdlib.h>

int n;
int indeg[20];
int queue[20];
int front, rear;
int count;

int bfs(int mat[n][n])
{
    front = rear = -1;
    count = 0;

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            queue[++rear] = i;
    }

    while (front != rear)
    {
        int curr = queue[++front];

        count++;

        for (int i = 0; i < n; i++)
        {
            count++;

            if (mat[curr][i])
            {
                indeg[i]--;

                if (indeg[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    return 0;
}

void tester()
{
    printf("\n--- TOPOLOGICAL SORT (SOURCE REMOVAL) TESTER ---\n");
    printf("Enter number of vertices (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0)
    {
        printf("Invalid vertex count! Maximum allowed is 20.\n");
        return;
    }

    int mat[n][n];

    for (int i = 0; i < n; i++)
    {
        indeg[i] = 0;
    }

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 1)
            {
                indeg[j]++;
            }
        }
    }

    bfs(mat);

    if (rear + 1 == n)
    {
        printf("\nTopological Sorting Order (Source Removal):\n");
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nGraph contains a cycle! Topological ordering is not possible.\n");
    }

    printf("Operation count = %d\n", count);
}

void plotter()
{
    FILE *fb, *fw;

    fb = fopen("SrcRemBest.txt", "w");
    fw = fopen("SrcRemWorst.txt", "w");

    for (int k = 1; k <= 20; k++)
    {
        n = k;

        int adjMat[n][n];

        for (int i = 0; i < n; i++)
            indeg[i] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = 0;

        bfs(adjMat);

        fprintf(fb, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
            indeg[i] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                adjMat[i][j] = 1;
                indeg[j]++;
            }
        }

        bfs(adjMat);

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