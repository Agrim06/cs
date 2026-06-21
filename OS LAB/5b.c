#include <stdio.h>

typedef struct
{
    int Id, AT, BT, CT, TAT, WT, RT, isCompl;
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

        p[i].isCompl = 0;
    }

    int curTime = 0;
    int completed = 0;

    int totalWT = 0;
    int totalTAT = 0;
    int totalRT = 0;

    printf("\nGantt Chart:\n");

    while(completed != n)
    {
        int minIndex = -1;
        int minBT = 9999;

        for(int i = 0; i < n; i++)
        {
            if(p[i].AT <= curTime &&
               p[i].isCompl == 0)
            {
                if(p[i].BT < minBT)
                {
                    minBT = p[i].BT;
                    minIndex = i;
                }
            }
        }

        if(minIndex == -1)
        {
            printf("(%d) Idle (%d) ",
                   curTime,
                   curTime + 1);

            curTime++;
        }
        else
        {
            int startTime = curTime;

            p[minIndex].RT = startTime - p[minIndex].AT;
            curTime += p[minIndex].BT;
            p[minIndex].CT = curTime;
            p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
            p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
            p[minIndex].isCompl = 1;
            completed++;

            printf("(%d) P%d (%d) ",
                   startTime,
                   p[minIndex].Id,
                   curTime);
        }
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

        totalTAT += p[i].TAT;
        totalWT += p[i].WT;
        totalRT += p[i].RT;
    }

    printf("\nAverage TAT = %.2f",
           (float)totalTAT / n);

    printf("\nAverage WT = %.2f",
           (float)totalWT / n);

    printf("\nAverage RT = %.2f\n",
           (float)totalRT / n);

    return 0;
}