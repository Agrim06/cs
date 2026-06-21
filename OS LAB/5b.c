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
    int remainingBT[n];
    int isFirstResponse[n];

    for(int i = 0; i < n; i++)
    {
        p[i].Id = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("AT: ");
        scanf("%d", &p[i].AT);

        printf("BT: ");
        scanf("%d", &p[i].BT);

        remainingBT[i] = p[i].BT;
        p[i].isCompl = 0;
        isFirstResponse[i] = 1;
    }

    int curTime = 0;
    int completed = 0;

    int totalWT = 0;
    int totalTAT = 0;
    int totalRT = 0;

    printf("\nGantt Chart:\n");
    
    int prevProcess = -1;

    while(completed != n)
    {
        int minIndex = -1;
        int minBT = 9999;

        for(int i = 0; i < n; i++)
        {
            if(p[i].AT <= curTime && p[i].isCompl == 0)
            {
                if(remainingBT[i] < minBT)
                {
                    minBT = remainingBT[i];
                    minIndex = i;
                }
                else if(remainingBT[i] == minBT)
                {
                    if(p[i].AT < p[minIndex].AT)
                    {
                        minIndex = i;
                    }
                }
            }
        }

        if(minIndex == -1)
        {
            if(prevProcess != -2)
            {
                printf("(%d) Idle ", curTime);
            }
            prevProcess = -2;
            curTime++;
        }
        else
        {
            if(isFirstResponse[minIndex] == 1)
            {
                p[minIndex].RT = curTime - p[minIndex].AT;
                isFirstResponse[minIndex] = 0;
            }

            if(prevProcess != minIndex)
            {
                printf("(%d) P%d ", curTime, p[minIndex].Id);
                prevProcess = minIndex;
            }

            remainingBT[minIndex]--;
            curTime++;

            if(remainingBT[minIndex] == 0)
            {
                p[minIndex].CT = curTime;
                p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
                p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
                p[minIndex].isCompl = 1;
                completed++;
            }
        }
    }
    printf("(%d)\n", curTime);

    printf("\nId\tAT\tBT\tCT\tTAT\tWT\tRT\n");

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

    printf("\nAverage TAT = %.2f", (float)totalTAT / n);
    printf("\nAverage WT = %.2f", (float)totalWT / n);
    printf("\nAverage RT = %.2f\n", (float)totalRT / n);

    return 0;
}