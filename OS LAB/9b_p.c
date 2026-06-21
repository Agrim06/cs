#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int i, n;
    int *ptr;

    int shmid = shmget(1234, 1024, 0666);

    ptr = (int *)shmat(shmid, NULL, 0);

    n = ptr[0];

    printf("Parent: Fibonacci Series Read from Shared Memory\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    shmdt(ptr);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}