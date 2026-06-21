#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    int shmid;
    void *ptr;
    pid_t pid;

    if (argc != 2)
    {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    shmid = shmget((key_t)1122, 4096, 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        printf("Shared memory creation failed\n");
        return 1;
    }

    ptr = shmat(shmid, NULL, 0);

    pid = fork();

    if (pid == 0)
    {
        execlp("./fib", "fib", argv[1], NULL);
    }
    else if (pid > 0)
    {
        wait(NULL);

        printf("\nPARENT: Child completed\n");
        printf("Fibonacci Series:\n");

        printf("%s\n", (char *)ptr);

        shmdt(ptr);
    }

    return 0;
}