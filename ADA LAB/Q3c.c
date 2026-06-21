//Selection Sort

#include<stdio.h>
#include<stdlib.h>

int count;

void selectionsort(int *a, int n)
{
    int i, j, min, t;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(*(a + j) < *(a + min))
                min = j;

            count++;
        }

        if(min != i)
        {
            t = *(a + min);
            *(a + min) = *(a + i);
            *(a + i) = t;
        }
    }
}

void plotter()
{
    FILE *f;

    f = fopen("selectionsort.txt", "a");

    int n = 10;

    while(n <= 30000)
    {
        int *a = (int *)malloc(sizeof(int) * n);

        for(int i = 0; i < n; i++)
            *(a + i) = i;

        count = 0;

        selectionsort(a, n);

        fprintf(f, "%d\t%d\n", n, count);

        printf("%d\t%d\n", n, count);

        free(a);

        if(n < 10000)
            n *= 10;
        else
            n += 10000;
    }

    fclose(f);
}

int main()
{
    plotter();
    return 0;
}