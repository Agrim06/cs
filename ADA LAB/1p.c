
#include <stdio.h>

#define START 10
#define END 100

int euclid(int m, int n)
{
    int count = 0;

    while (n)
    {
        count++;
        int r = m % n;
        m = n;
        n = r;
    }
    return count;
}

int consecutive(int m, int n)
{
    int min = m > n ? n : m;
    int count = 0;

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

int modified(int m, int n)
{
    int count = 0;

    int t;

    while (n > 0)
    {
        if (n > m)
        {
            t = n;
            n = m;
            m = t;
        }

        m -= n;
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
                default:
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
        fprintf(best, "%d\t%.0f\n", i, minCount);
        fprintf(worst, "%d\t%.0f\n", i, maxCount);
        
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
