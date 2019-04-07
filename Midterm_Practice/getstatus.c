#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern int errno;

int main(int argc, char **argv)
{
    int status;
    int pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid > 0)
    {
        int w_ret = waitpid(pid, &status, 0);
        if (w_ret == -1)
        {
            perror("waitpid");
        }
        else
        {
            if(WIFEXITED(status)){
                char buff[50];
                int s_ret = sprintf(buff, "%i\n", WEXITSTATUS(status));
                write(STDOUT_FILENO, buff, s_ret);
            }
        }
    }
    else
    {
        int sum;
        char buf[50];
        write(STDOUT_FILENO, "Input:", 6);
        int r_ret = read(STDIN_FILENO, buf, 50);
        buf[r_ret - 1] = '\0';
        sum = atoi(buf);
        _exit(sum);
    }
    
}