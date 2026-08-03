#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void heapify(int arr[], int n, int i)
{
    int maxIdx = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
    {
        count++;
        if (arr[left] > arr[maxIdx])
            maxIdx = left;
    }

    if (right < n)
    {
        count++;
        if (arr[right] > arr[maxIdx])
            maxIdx = right;
    }

    if (maxIdx != i)
    {
        int temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;

        heapify(arr, n, maxIdx);
    }
}

void heapSort(int arr[], int n)
{
    int i;

    count = 0;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void tester()
{
    int arr[20];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("\nSorted Array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    printf("\nBasic Operation Count = %d\n", count);
}
void plotter()
{
    FILE *fp1, *fp2;
    int arr[1000];
    int n, i;

    fp1 = fopen("heapbest.txt", "w");
    fp2 = fopen("heapworst.txt", "w");

    for (n = 10; n <= 200; n += 10)
    {

        for (i = 0; i < n; i++)
            arr[i] = i + 1;

        heapSort(arr, n);

        fprintf(fp1, "%d\t%d\n", n, count);

        for (i = 0; i < n; i++)
            arr[i] = n - i;

        heapSort(arr, n);

        fprintf(fp2, "%d\t%d\n", n, count);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Data files generated successfully.\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("ENTER YOUR CHOICE: \n1.Tester\n2.Plotter\n0.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            tester();
            break;

        case 2:
            plotter();
            break;

        case 0:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
}