#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsackBottomUp(int W, int wt[], int val[], int n)
{
    int K[n + 1][W + 1];
    count = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            count++;
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

void tester()
{
    int n, W;
    printf("\n--- BOTTOM-UP KNAPSACK TESTER ---\n");
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &W);

    int maxProfit = knapsackBottomUp(W, wt, val, n);
    printf("Maximum Value / Profit = %d\n", maxProfit);
    printf("Operation Count = %d\n", count);
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("knapsack_bottomup.txt", "w");

    for (int n = 5; n <= 50; n += 5)
    {
        int W = n * 10;
        int *val = (int *)malloc(n * sizeof(int));
        int *wt = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            val[i] = rand() % 100 + 1;
            wt[i] = rand() % W + 1;
        }

        knapsackBottomUp(W, wt, val, n);
        fprintf(fp, "%d\t%d\n", n, count);

        free(val);
        free(wt);
    }
    fclose(fp);
    printf("Data generated in knapsack_bottomup.txt\n");
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