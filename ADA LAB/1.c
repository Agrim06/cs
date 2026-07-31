#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count = 0;

int gcdEuclid(int m, int n)
{
    count = 0;
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
        count++;
    }

    return m;
}

int gcdConsecutiveIntegerCheck(int m, int n)
{
    count = 0;
    int t = m > n ? n : m;
    for (int i = t; i > 0; i--)
    {
        count++;
        if (m % i == 0)
        {
            count++;
            if (n % i == 0)
                return i;
        }
    }

    return m > n ? m : n;
}

int modifiedEuclids(int m, int n)
{
    count = 1;

    while (m != n)
    {
        if (m > n)
            m -= n;
        else
            n -= m;

        count++;
    }

    count++;

    return m;
}

void tester()
{
    int choice, m, n, res;
    while (1)
    {
        printf("\n--- GCD TESTER ---\n");
        printf("1. Euclid Algorithm\n");
        printf("2. Consecutive Integer Check\n");
        printf("3. Modified Euclid Algorithm\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice!\n");
            continue;
        }

        printf("ENTER THE VALUES M AND N: ");
        scanf("%d %d", &m, &n);

        switch (choice)
        {
        case 1:
            res = gcdEuclid(m, n);
            printf("THE GCD IS %d\n", res);
            printf("Operation count = %d\n", count);
            break;
        case 2:
            res = gcdConsecutiveIntegerCheck(m, n);
            printf("THE GCD IS %d\n", res);
            printf("Operation count = %d\n", count);
            break;
        case 3:
            res = modifiedEuclids(m, n);
            printf("THE GCD IS %d\n", res);
            printf("Operation count = %d\n", count);
            break;
        }
    }
}

void plotter()
{
    FILE *f1 = fopen("euclidBest.txt", "w");
    FILE *f2 = fopen("euclidWorst.txt", "w");
    FILE *f3 = fopen("consecBest.txt", "w");
    FILE *f4 = fopen("consecWorst.txt", "w");
    FILE *f5 = fopen("modifiedBest.txt", "w");
    FILE *f6 = fopen("modifiedWorst.txt", "w");

    for (int i = 10; i <= 100; i += 10)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                gcdEuclid(j, k);
                if (count < min)
                    min = count;
                if (count > max)
                    max = count;
            }
        }
        fprintf(f1, "%d\t%d\n", i, min);
        fprintf(f2, "%d\t%d\n", i, max);
    }

    for (int i = 10; i <= 100; i += 10)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                gcdConsecutiveIntegerCheck(j, k);
                if (count < min)
                    min = count;
                if (count > max)
                    max = count;
            }
        }
        fprintf(f3, "%d\t%d\n", i, min);
        fprintf(f4, "%d\t%d\n", i, max);
    }

    for (int i = 10; i <= 100; i += 10)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                modifiedEuclids(j, k);
                if (count < min)
                    min = count;
                if (count > max)
                    max = count;
            }
        }
        fprintf(f5, "%d\t%d\n", i, min);
        fprintf(f6, "%d\t%d\n", i, max);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);

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
