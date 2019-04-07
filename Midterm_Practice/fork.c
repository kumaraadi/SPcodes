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
extern int errno;

int main(int argc, char **argv)
{

    int var = 5;
    int var2 = 6;
    int pid;
    int fd1 = open("file.txt", O_WRONLY);

    pid = fork();

    int ret = write(fd1, "ABCD", 4);
    if (ret == -1)
    {
        perror("write");
    }

    if (pid < 0)
    {
        _exit(0);
    }
    else if (pid == 0)
    {
        ret = write(fd1, "123", 3);
        if (ret == -1)
        {
            perror("write");
        }
    }
    else
    {
        write(fd1, "PARENT", 6);
    }
}
