#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;
int F[100][100];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int mfKnapsack(int i, int j, int wt[], int val[])
{
    count++;
    if (F[i][j] < 0)
    {
        int value;
        if (j < wt[i - 1])
            value = mfKnapsack(i - 1, j, wt, val);
        else
            value = max(mfKnapsack(i - 1, j, wt, val), val[i - 1] + mfKnapsack(i - 1, j - wt[i - 1], wt, val));
        
        F[i][j] = value;
    }
    return F[i][j];
}

void tester()
{
    int n, W;
    printf("\n--- MEMORY FUNCTION KNAPSACK TESTER ---\n");
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &W);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0) F[i][j] = 0;
            else F[i][j] = -1;
        }
    }

    count = 0;
    int maxProfit = mfKnapsack(n, W, wt, val);
    printf("Maximum Value / Profit = %d\n", maxProfit);
    printf("Operation Count = %d\n", count);
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("knapsack_memfunc.txt", "w");

    for (int n = 5; n <= 40; n += 5)
    {
        int W = 50;
        int *val = (int *)malloc(n * sizeof(int));
        int *wt = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            val[i] = rand() % 100 + 1;
            wt[i] = rand() % W + 1;
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0) F[i][j] = 0;
                else F[i][j] = -1;
            }
        }

        count = 0;
        mfKnapsack(n, W, wt, val);
        fprintf(fp, "%d\t%d\n", n, count);

        free(val);
        free(wt);
    }
    fclose(fp);
    printf("Data generated in knapsack_memfunc.txt\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Tester\n2. Plotter\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) tester();
        else if (choice == 2) plotter();
        else printf("Invalid choice!\n");
    }
    return 0;
}