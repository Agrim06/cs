#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;
int bubblesort(int *a, int n)
{
    count = 0;
    int i, j, t, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            count++;
            if (a[j] > a[j + 1])
            {
                t = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = t;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    return count;
}

void insertionSort(int *arr, int n)
{
    count = 0;
    for (int i = 1; i < n; i++)
    {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            count++;
            if (arr[j] > val)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else 
                break;
        }
        arr[j + 1] = val;
    }
}

void selectionSort(int *arr, int n)
{
    count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = pos + 1; j < n; j++)
        {
            count++;
            if (arr[pos] > arr[j])
                pos = j;
        }
        if (pos != i)
        {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
        }
    }
}

void plotter1()
{
    int *arr, n;
    srand(time(NULL));

    FILE *f1, *f2, *f3;
    f1 = fopen("Bubblebest.txt", "w");
    f2 = fopen("Bubbleworst.txt", "w");
    f3 = fopen("Bubbleavg.txt", "w");
    n = 10;
     
    while (n <= 30000)
    {
        arr = (int *)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++)
        {
            *(arr + i) = n - i;
        }
        bubblesort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
        {
            *(arr + i) = i + 1;
        }
        bubblesort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
        {
            *(arr + i) = rand() % n;
        }
        bubblesort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void plotter2()
{
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3;
    f1 = fopen("Insertionbest.txt", "w");
    f2 = fopen("Insertionworst.txt", "w");
    f3 = fopen("Insertionavg.txt", "w");
    n = 10;
    while (n <= 30000)
    {
        arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            *(arr + i) = n - i;
        }
        insertionSort(arr, n); 
        fprintf(f2, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
        {
            *(arr + i) = i + 1;
        }
        insertionSort(arr, n); 
        fprintf(f1, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
        {
            *(arr + i) = rand() % n;
        }
        insertionSort(arr, n);  
        fprintf(f3, "%d\t%d\n", n, count);
        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void plotter3()
{
    FILE *f;
    f = fopen("selectionsort.txt", "w");
    int j;
    int n = 10;
    while (n <= 30000)
    {
        int *a = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            *(a + i) = i;
        count = 0;
        selectionSort(a, n);
        fprintf(f, "%d\t%d\n", n, count);
        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        free(a);
    }
}

void main()
{
    plotter1();
    plotter2();
    plotter3();
}