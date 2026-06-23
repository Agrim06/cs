#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int linearSearch(int *a, int n, int k)
{
    int i;
    count = 0;
    for (i = 0; i < n; i++)
    {
        count++;
        if (a[i] == k)
        {
            return i;
        }
    }
    return -1;
}

void plotter()
{
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("linearbest.txt", "w");
    f2 = fopen("linearavg.txt", "w");
    f3 = fopen("linearworst.txt", "w");
    n = 2;
    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        r = linearSearch(arr, n, 1);
        fprintf(f1, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n;
        r = linearSearch(arr, n, key);
        fprintf(f2, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        r = linearSearch(arr, n, 1);
        fprintf(f3, "%d\t%d\n", n, count);
        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void main()
{
    plotter();
}