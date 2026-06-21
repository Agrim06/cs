#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int n, i;
    int *ptr;

    int shmid = shmget(1234, 1024, 0666);

    ptr = (int *)shmat(shmid, NULL, 0);

    printf("Enter n: ");
    scanf("%d", &n);

    ptr[0] = n;

    int a = 0, b = 1, c;

    ptr[1] = a;

    if(n > 1)
        ptr[2] = b;

    for(i = 2; i < n; i++)
    {
        c = a + b;
        ptr[i + 1] = c;
        a = b;
        b = c;
    }

    printf("Child: Fibonacci Series Written to Shared Memory\n");

    shmdt(ptr);

    return 0;
}