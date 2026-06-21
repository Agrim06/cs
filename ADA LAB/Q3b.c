// Insertion Sort 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

void insertionSort(int *arr, int n)
{
    count = 0;

    for(int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i - 1;

        while(count++ && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;

            if(j < 0)
                break;
        }

        arr[j + 1] = value;
    }
}

void plotter()
{
    int *arr, n;

    srand(time(NULL));

    FILE *f1, *f2, *f3;

    f1 = fopen("INSERTIONBEST.txt", "a");
    f2 = fopen("INSERTIONWORST.txt", "a");
    f3 = fopen("INSERTIONAVG.txt", "a");

    n = 10;

    while(n <= 30000)
    {
        arr = (int *)malloc(sizeof(int) * n);

        /* Worst Case */
        for(int i = 0; i < n; i++)
            arr[i] = n - i;

        count = 0;
        insertionSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        /* Best Case */
        for(int i = 0; i < n; i++)
            arr[i] = i + 1;

        count = 0;
        insertionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        /* Average Case */
        for(int i = 0; i < n; i++)
            arr[i] = rand() % n;

        count = 0;
        insertionSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        free(arr);

        if(n < 10000)
            n *= 10;
        else
            n += 10000;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    plotter();
    return 0;
}