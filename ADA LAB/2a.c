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

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    index = linearSearch(arr, n, key);

    if (index != -1)
    {
        printf("Key found at index %d\n", index);
    }
    else
    {
        printf("Key not found!\n");
    }

    printf("Number of comparisons = %d\n", count);

    free(arr);
}

void plotter()
{
    srand(time(NULL));
    int *arr;
    int n, key;
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
        linearSearch(arr, n, 1);
        fprintf(f1, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n;
        linearSearch(arr, n, key);
        fprintf(f2, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        linearSearch(arr, n, 1);
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