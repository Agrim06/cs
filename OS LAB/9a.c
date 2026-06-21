#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    int n;

    fd1 = open("input.txt", O_RDONLY);

    if(fd1 == -1)
    {
        printf("Cannot open input file\n");
        exit(1);
    }

    fd2 = open("output.txt",
               O_WRONLY | O_CREAT | O_TRUNC,
               0644);

    if(fd2 == -1)
    {
        printf("Cannot create output file\n");
        exit(1);
    }

    while((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");

    return 0;
}