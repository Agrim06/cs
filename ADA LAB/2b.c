#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int binarySearch(int key, int *a, int high, int low)
{
    count++;
    int mid = (high + low) / 2;
    if (low > high)
        return -1;
    if (*(a + mid) == key)
        return mid;
    else if (*(a + mid) > key)
        return binarySearch(key, a, mid - 1, low);
    else
        return binarySearch(key, a, high, mid + 1);
}

void tester()
{
    int n, key, index;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements in SORTED order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    count = 0;
    index = binarySearch(key, arr, n - 1, 0);

    if (index != -1)
    {
        printf("Key found at index %d\n", index);
    }
    else
    {
        printf("Key not found!\n");
    }

    printf("Number of comparisons/calls = %d\n", count);

    free(arr);
}

void plotter()
{
    srand(time(NULL));
    int *arr;
    int n, key;
    FILE *f1, *f2, *f3;
    f1 = fopen("binarybest.txt", "w");
    f2 = fopen("binaryavg.txt", "w");
    f3 = fopen("binaryworst.txt", "w");
    n = 2;
    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        int mid = (n - 1) / 2;
        *(arr + mid) = 0;
        count = 0;
        binarySearch(0, arr, n - 1, 0);
        fprintf(f1, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
            *(arr + i) = i + 1;
        key = rand() % n + 1;
        count = 0;
        binarySearch(key, arr, n - 1, 0);
        fprintf(f2, "%d\t%d\n", n, count);

        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        count = 0;
        binarySearch(1, arr, n - 1, 0);
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