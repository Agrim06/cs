#include <stdio.h>

typedef struct
{
    int Id, AT, BT, remBT;
    int CT, TAT, WT, RT;
} Process;

void sjfPreemptive(Process p[], int n);

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

        p[i].remBT = p[i].BT;
    }

    sjfPreemptive(p, n);

    return 0;
}

void sjfPreemptive(Process p[], int n)
{
    int timeTrack[100];
    int processTrack[100];

    int j = -1, k = -1;

    int curTime = 0;
    int completed = n;

    int totalWT = 0;
    int totalTAT = 0;
    int totalRT = 0;

    timeTrack[++j] = 0;

    while(completed)
    {
        int minIndex = -1;
        int minBT = 9999;

        for(int i = 0; i < n; i++)
        {
            if(p[i].AT <= curTime &&
               p[i].remBT > 0)
            {
                if(p[i].remBT < minBT)
                {
                    minBT = p[i].remBT;
                    minIndex = i;
                }
            }
        }

        if(minIndex == -1)
        {
            processTrack[++k] = 0;

            curTime++;

            timeTrack[++j] = curTime;

            continue;
        }

        if(p[minIndex].remBT == p[minIndex].BT)
        {
            p[minIndex].RT =
                curTime - p[minIndex].AT;
        }

        p[minIndex].remBT--;

        curTime++;

        processTrack[++k] = p[minIndex].Id;

        timeTrack[++j] = curTime;

        if(p[minIndex].remBT == 0)
        {
            p[minIndex].CT = curTime;

            p[minIndex].TAT =
                p[minIndex].CT - p[minIndex].AT;

            p[minIndex].WT =
                p[minIndex].TAT - p[minIndex].BT;

            totalTAT += p[minIndex].TAT;
            totalWT += p[minIndex].WT;
            totalRT += p[minIndex].RT;

            completed--;
        }
    }

    printf("\nObservation Table\n");
    printf("Id\tAT\tBT\tCT\tTAT\tWT\tRT\n");

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

    printf("\nGantt Chart\n");

    for(int i = 0; i <= k; i++)
        printf("| P%d ", processTrack[i]);

    printf("|\n");

    for(int i = 0; i <= j; i++)
        printf("%d\t", timeTrack[i]);

    printf("\n");

    printf("\nAverage TAT = %.2f",
           (float)totalTAT / n);

    printf("\nAverage WT = %.2f",
           (float)totalWT / n);

    printf("\nAverage RT = %.2f\n",
           (float)totalRT / n);
}