#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd1, fd2, fd3;
    fd1 = open("result.txt", O_RDWR | O_CREAT, S_IRWXU);
    fd2 = open("result.txt", O_RDWR | O_CREAT);

    int cpid = fork();

    write(fd1, "123", 3);

    if (cpid == 0)
    {
        fd3 = open("result.txt", O_RDWR | O_APPEND);

        write(fd2, "ABCDDDDDDD", 7);
        write(fd3, "456", 3);
        close(fd3);
    }

    else if (cpid > 0)
    {
        int fd4 = open("result.txt", O_RDWR | O_TRUNC);

        write(fd4, "XYZ", 3);
        write(fd2, "LMN", 3);
        close(fd4);
    }

    close(fd1);
    close(fd2);
}