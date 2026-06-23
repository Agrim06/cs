#include <stdio.h>

struct Process
{
    int pid, at, bt, rt, ct, tat, wt;
};

int main()
{
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    int queue[100];
    int front = 0, rear = 0;

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int time = 0, completed = 0;

    for(int i = 0; i < n; i++)
    {
        if(p[i].at == 0)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    printf("\nGantt Chart:\n|");

    while(completed < n)
    {
        if(front == rear)
        {
            time++;

            for(int i = 0; i < n; i++)
            {
                if(!visited[i] && p[i].at <= time)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];

        printf(" P%d |", p[idx].pid);

        if(p[idx].rt > tq)
        {
            p[idx].rt -= tq;
            time += tq;
        }
        else
        {
            time += p[idx].rt;
            p[idx].rt = 0;

            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            completed++;
        }

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && p[i].at <= time)
            {
                queue[rear++] = i;
                visited[i] = 1;
                
            }
        }

        if(p[idx].rt > 0)
            queue[rear++] = idx;
    }

    float avg_tat = 0, avg_wt = 0;

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}