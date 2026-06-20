#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    int shmid;
    void *ptr;

    shmid = shmget((key_t)1122, 4096, 0666);

    ptr = shmat(shmid, NULL, 0);

    int n = atoi(argv[1]);

    int n1 = 0;
    int n2 = 1;
    int n3;
    int k = 2;

    printf("CHILD:\n");

    sprintf((char *)ptr, "%d %d ", n1, n2);

    ptr += strlen((char *)ptr);

    printf("%d %d ", n1, n2);

    while (k < n)
    {
        n3 = n1 + n2;

        sprintf((char *)ptr, "%d ", n3);

        printf("%d ", n3);

        ptr += strlen((char *)ptr);

        n1 = n2;
        n2 = n3;

        k++;
    }

    printf("\n");

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}