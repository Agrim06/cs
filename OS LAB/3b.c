#include <stdio.h>

typedef struct
{
    int Id, AT, BT, CT, TAT, WT, RT;
} Process;

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].Id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("AT: ");
        scanf("%d", &p[i].AT);

        printf("BT: ");
        scanf("%d", &p[i].BT);
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(p[j].AT > p[j + 1].AT)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int curTime = 0;
    int totalWT = 0, totalTAT = 0, totalRT = 0;

    printf("\nGantt Chart:\n");

    for(int i = 0; i < n; i++)
    {
        if(curTime < p[i].AT)
            curTime = p[i].AT;

        int startTime = curTime;

        p[i].RT = startTime - p[i].AT;

        curTime += p[i].BT;

        p[i].CT = curTime;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;

        printf("(%d) P%d (%d) ",
               startTime,
               p[i].Id,
               curTime);

        totalTAT += p[i].TAT;
        totalWT += p[i].WT;
        totalRT += p[i].RT;
    }

    printf("\n\nId\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].Id,
               p[i].AT,
               p[i].BT,
               p[i].CT,
               p[i].TAT,
               p[i].WT,
               p[i].RT);
    }

    printf("\nAverage TAT = %.2f",
           (float)totalTAT / n);

    printf("\nAverage WT = %.2f",
           (float)totalWT / n);

    printf("\nAverage RT = %.2f\n",
           (float)totalRT / n);

    return 0;
}