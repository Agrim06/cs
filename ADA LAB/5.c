#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void merge(int *arr, int beg, int mid, int end)
{
    int i, j, k;
    int n1 = (mid - beg) + 1;
    int n2 = end - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[beg + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + j + 1];
        
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        count++;
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int *arr, int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void worst(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        int i, j;
        int n1 = (mid - beg) + 1;
        int n2 = end - mid;
        int a[n1], b[n2];
        
        for (i = 0; i < n1; i++)
            a[i] = arr[(2 * i)];
        for (j = 0; j < n2; j++)
            b[j] = arr[(2 * j) + 1];
        worst(a, beg, mid);
        worst(b, mid + 1, end);
        for (i = 0; i < n1; i++)
            arr[i] = a[i];
        for (j = i; j < n2; j++)
            arr[j + 1] = b[j];
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

    printf("\n--- MERGE SORT TESTER ---\n");
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
    mergeSort(arr, 0, n - 1);

    printArray(arr, n);
    printf("Number of comparisons = %d\n", count);

    free(arr);
}

void plotter()
{
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3, *f4;
    f1 = fopen("Mergebest.txt", "w");
    f2 = fopen("Mergeworst.txt", "w");
    f3 = fopen("Mergeavg.txt", "w");
    f4 = fopen("Worstdata.txt", "w");
    for (n = 2; n <= 1024; n = n * 2)
    {
        arr = (int *)malloc(sizeof(int) * n);
        
        for (int i = 0; i < n; i++)
            *(arr + i) = i + 1;
        count = 0;
        mergeSort(arr, 0, n - 1); 
        fprintf(f1, "%d\t%d\n", n, count);
        count = 0;
        worst(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            fprintf(f4, "%d", *(arr + i));
        fprintf(f4, "\n");
        mergeSort(arr, 0, n - 1); 
        fprintf(f2, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        count = 0;
        mergeSort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count);
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
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