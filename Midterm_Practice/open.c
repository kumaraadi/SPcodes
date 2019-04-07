#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h> //write
#include </usr/include/asm/errno.h>
extern int errno;

int main(int argc, char *argv){
    int i = 0, fd = 0;
    char buff[50];

        fd = open("file.txt", O_CREAT | O_TRUNC);
        if(fd == -1){
            write(STDOUT_FILENO, "fd failed",9);
            perror("fd");
        }
        // printf("%d", fd);
        // int ret = write(5, NULL, 5);
        // perror("write");
        if(errno == ENOENT){
            perror("");
        }
        //write(STDOUT_FILENO, buff, ret);
    
}