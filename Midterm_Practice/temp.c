#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

int main()
{
    char buffer[50];
    int fd = open("file.txt", O_RDONLY);
    int w = read(fd, buffer, -2);
    if (w == -1)
    {
        printf("%d", errno);
        perror("Error: ");
    }
}