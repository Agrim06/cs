#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int beg, int end)
{
    int pivot = arr[beg];
    int i = beg, j = end + 1;
    do
    {
        do
        {
            count++;
            i++;
        } while (arr[i] < pivot);
        do
        {
            count++;
            j--;
        } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[i], &arr[j]);
    swap(&arr[beg], &arr[j]);
    return j;
}

void quicksort(int *arr, int beg, int end)
{
    if (beg < end)
    {
        int split = partition(arr, beg, end);
        quicksort(arr, beg, split - 1);
        quicksort(arr, split + 1, end);
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

    printf("\n--- QUICK SORT TESTER ---\n");
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

    count = 0;
    quicksort(arr, 0, n - 1);

    printArray(arr, n);
    printf("Number of comparisons = %d\n", count);

    free(arr);
}

void plotter()
{
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3;
    f1 = fopen("Quickbest.txt", "w");
    f2 = fopen("Quickworst.txt", "w");
    f3 = fopen("Quickavg.txt", "w");
    n = 4;
    
    while (n <= 1024)
    {
        arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            *(arr + i) = 5;
        count = 0;
       
        quicksort(arr, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count); 

        count = 0;
        for (int i = 0; i < n; i++)
            *(arr + i) = i + 1;
        quicksort(arr, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count); 

        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        count = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count); 
        n = n * 2;
        free(arr);
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