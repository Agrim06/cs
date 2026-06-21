//Linear & Binary Search

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int linearSearch(int *a, int key, int n)
{
    count = 0;

    for (int i = 0; i < n; i++)
    {
        count++;

        if (a[i] == key)
            return count;
    }

    return count;
}

int binarySearch(int key, int *a, int high, int low)
{
    count++;

    if (low > high)
        return count - 1;

    int mid = (high + low) / 2;

    if (a[mid] == key)
        return count;

    if (a[mid] > key)
        return binarySearch(key, a, mid - 1, low);

    return binarySearch(key, a, high, mid + 1);
}

void linearPlotter()
{
    FILE *best = fopen("linear_best.txt", "w");
    FILE *avg = fopen("linear_avg.txt", "w");
    FILE *worst = fopen("linear_worst.txt", "w");

    int n = 2;

    while (n <= 1024)
    {
        int *arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            arr[i] = 1;

        fprintf(best, "%d\t%d\n", n,
                linearSearch(arr, 1, n));

        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;

        fprintf(avg, "%d\t%d\n", n,
                linearSearch(arr, rand() % n, n));

        for (int i = 0; i < n; i++)
            arr[i] = 0;

        fprintf(worst, "%d\t%d\n", n,
                linearSearch(arr, 1, n));

        free(arr);
        n *= 2;
    }

    fclose(best);
    fclose(avg);
    fclose(worst);
}

void binaryPlotter()
{
    FILE *best = fopen("binary_best.txt", "w");
    FILE *avg = fopen("binary_avg.txt", "w");
    FILE *worst = fopen("binary_worst.txt", "w");

    int n = 2;

    while (n <= 1024)
    {
        int *arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            arr[i] = 1;

        int mid = (n - 1) / 2;
        arr[mid] = 0;

        count = 0;
        fprintf(best, "%d\t%d\n", n,
                binarySearch(0, arr, n - 1, 0));

        count = 0;
        fprintf(avg, "%d\t%d\n", n,
                binarySearch(-1, arr, n - 1, 0));

        count = 0;
        fprintf(worst, "%d\t%d\n", n,
                binarySearch(2, arr, n - 1, 0));

        free(arr);
        n *= 2;
    }

    fclose(best);
    fclose(avg);
    fclose(worst);
}

int main()
{
    srand(time(NULL));

    linearPlotter();
    binaryPlotter();

    return 0;
}