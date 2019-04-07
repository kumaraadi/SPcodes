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

int main(int argc, char** argv) {

    int pid = fork();

    if (pid > 0) {
        sleep(1);
        
        char inputstr1[10];
        
        int fd2 = open("file.txt", O_RDWR);
        int readinput1=1;

       
            readinput1 = read(fd2, inputstr1, 10);

            int input1, input2;
            sscanf(inputstr1, "%d %d", &input1, &input2);

            int result = input1 + input2;
            char buff[10];
            sprintf(buff, "%d", result);
            write(STDOUT_FILENO, buff, 10);

      

        close(fd2);
        wait(NULL);

    } else if(pid==0) {
        int fd = open("file.txt", O_RDWR|O_TRUNC);

        
        char inputstr[50];
        int readinput, writeinput;
        int i = 0;
        for (i = 0; i < 10; i = i + 1) {
            readinput = read(STDIN_FILENO, inputstr, 50);
            writeinput = write(fd, inputstr, readinput);
        }
        close(fd);
    }



    return (EXIT_SUCCESS);
}
