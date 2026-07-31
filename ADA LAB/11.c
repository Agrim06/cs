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
    count1 = 0;
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

void printArray(int *arr, int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void tester()
{
    int n;
    int *arr;

    printf("\n--- HEAP SORT TESTER ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printArray(arr, n);
    printf("Heap construction comparisons = %d\n", count2);
    printf("Sorting extraction comparisons = %d\n", count1);
    printf("Total comparisons = %d\n", count1 + count2);

    free(arr);
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