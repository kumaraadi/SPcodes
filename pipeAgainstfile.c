#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MSGSIZE 20

int main()
{
    char buff[50];
    char inbuf[MSGSIZE];
    int p1[2], p2[2], pid, nbytes;

    pipe(p1);
    pipe(p2);

    pid = fork();

    if ((pid== 0)
    {
        char temp[MSGSIZE];
        write(STDOUT_FILENO, "input:", 6);
        int ret = read(STDIN_FILENO, inbuf, 20);

        write(p1[1], inbuf, ret);
        int re = 2;
        re = read(p2[0], temp, MSGSIZE);

        if (re != 0)
        {
            write(STDOUT_FILENO, temp, re);
        }
    }
    else if(pid > 0)
    {
        sleep(1);
        char buf_read[MSGSIZE];
        char buf_write[MSGSIZE];
        int sum = 0;
        int nbytes2 = read(p1[0], buf_read, MSGSIZE);
        char temp2[20];
        strcpy(temp2, buf_read);
        temp2[nbytes2] = '\0';
        char *token = strtok(buf_read, " ");
        while (token != NULL)
        {
            sum += atoi(token);
            token = strtok(NULL, " ");
        }

        int r = sprintf(buf_write, "%d", sum);
        //write(STDOUT_FILENO, buf_write, r);
        write(p2[1], buf_write, r);
    }
    return 0;
}

//exit(-1) gives what number? 254? wrapping
//int num = atoi(buff); nhn chalega, because no \0