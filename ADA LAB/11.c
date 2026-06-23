#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count1 = 0, count2;

void heapify(int *arr, int i, int size)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;

    if (left < size && ++count1 && arr[left] > arr[maxIdx])
    {
        maxIdx = left;
    }

    if (right < size && ++count1 && arr[right] > arr[maxIdx])
    {
        maxIdx = right;
    }

    if (maxIdx != i)
    {
        int temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;

        heapify(arr, maxIdx, size);
    }
}

void heapSort(int *arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    count2 = count1;
    count1 = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, 0, i);
    }
}

void plotter()
{
    srand(time(NULL));
    FILE *f1, *f2, *f3;
    f1 = fopen("heapBest.txt", "w");
    f2 = fopen("heapWorst.txt", "w");
    f3 = fopen("heapAvg.txt", "w");

    int n = 100;

    while (n <= 1000)
    {
        int arr[n];

        for (int i = 0; i < n; i++)
            arr[i] = n - i + 1;
        count1 = 0;
        heapSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count1 > count2 ? count1 : count2);

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        count1 = 0;
        heapSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count1 > count2 ? count1 : count2);

        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        count1 = 0;
        heapSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count1 > count2 ? count1 : count2);

        n += 100;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void main()
{
    plotter();
}