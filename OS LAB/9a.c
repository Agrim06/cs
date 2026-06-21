#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int f1, f2;
    char buffer[100];
    int n;

    f1 = open("input.txt", O_RDONLY);

    if(f1 == -1)
    {
        printf("Cannot open input file\n");
        exit(1);
    }

    f2 = open("output.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);

    if(f2 == -1)
    {
        printf("Cannot create output file\n");
        exit(1);
    }

    while((n = read(f1, buffer, sizeof(buffer))) > 0)
    {
        write(f2, buffer, n);
    }

    close(f1);
    close(f2);

    printf("File copied successfully\n");

    return 0;
}