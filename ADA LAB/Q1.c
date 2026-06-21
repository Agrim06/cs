// Implement Euclid's, consecutive integer checking and modified Euclid‟s algorithms to find GCD of two nonnegative integers and perform comparative analysis.

#include <stdio.h>

#define START 10
#define END 100

float euclid(int m, int n)
{
    int r;
    float count = 0;

    while (n)
    {
        count++;
        r = m % n;
        m = n;
        n = r;
    }

    return count;
}

float consecutive(int m, int n)
{
    int min = (m < n) ? m : n;
    float count = 0;

    while (1)
    {
        count++;

        if (m % min == 0)
        {
            count++;

            if (n % min == 0)
                break;
        }

        min--;
    }

    return count;
}

float modified(int m, int n)
{
    int temp;
    float count = 0;

    while (n > 0)
    {
        if (n > m)
        {
            temp = m;
            m = n;
            n = temp;
        }

        m = m - n;
        count++;
    }

    return count;
}

void analysis(int ch)
{
    FILE *best, *worst;

    for (int i = START; i <= END; i += 10)
    {
        float minCount = 10000;
        float maxCount = 0;

        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                float count = 0;

                switch (ch)
                {
                case 1:
                    count = euclid(j, k);
                    break;
                case 2:
                    count = consecutive(j, k);
                    break;
                case 3:
                    count = modified(j, k);
                    break;
                }

                if (count > maxCount)
                    maxCount = count;

                if (count < minCount)
                    minCount = count;
            }
        }

        switch (ch)
        {
        case 1:
            best = fopen("euclid_best.txt", "a");
            worst = fopen("euclid_worst.txt", "a");
            break;

        case 2:
            best = fopen("consecutive_best.txt", "a");
            worst = fopen("consecutive_worst.txt", "a");
            break;

        case 3:
            best = fopen("modified_best.txt", "a");
            worst = fopen("modified_worst.txt", "a");
            break;
        }

        fprintf(best, "%d %.2f\n", i, minCount);
        fprintf(worst, "%d %.2f\n", i, maxCount);

        fclose(best);
        fclose(worst);
    }
}

int main()
{
    analysis(1);
    analysis(2);
    analysis(3);

    return 0;
}