#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int my_system(char *cmd)
{
    int pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        return -1;
    }
    else if (pid == 0)
    {
        char *argv[4];
        argv[0] = "sh";
        argv[1] = "-c";
        argv[2] = "cmd";
        argv[3] = NULL;

        execp("/bin/sh", argv);
        exit(-1);
    }

    if(waitpid(pid, &status, 0)==-1){
        return -1;
    }else if(WIFEXITED(status)){
        return(WEXITSTATUS(status));
    }
}
int main()
{
    my_system("ls");
}