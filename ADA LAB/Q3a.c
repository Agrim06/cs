// BubbleSort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long count;

void bubbleSort(int *a, int n)
{
    int temp, flag;

    count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            count++;

            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }

        if (!flag)
            break;
    }
}

int main()
{
    FILE *best = fopen("bubble_best.txt", "w");
    FILE *avg = fopen("bubble_avg.txt", "w");
    FILE *worst = fopen("bubble_worst.txt", "w");

    srand(time(NULL));

    int n = 10;

    while (n <= 30000)
    {
        int *arr = malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        bubbleSort(arr, n);
        fprintf(best, "%d\t%lld\n", n, count);

        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        bubbleSort(arr, n);
        fprintf(worst, "%d\t%lld\n", n, count);

        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;

        bubbleSort(arr, n);
        fprintf(avg, "%d\t%lld\n", n, count);

        free(arr);

        if (n < 10000)
            n *= 10;
        else
            n += 10000;
    }

    fclose(best);
    fclose(avg);
    fclose(worst);

    return 0;
}