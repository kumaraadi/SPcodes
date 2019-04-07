//You face problems in child process communication
//major issue, if parent dies, then child doesnt know
//and it will assume parent is writing
//EOF
//two pointers
//PIPES come in handy
// int fd[2]
// pipe(fd);
//pipe is for parent and child only
//pipe fork se pehly krna hota h
//it is uni direction comm machenism
//fd[0] read, fd[1] write 
//Programmer defines who does what
//advantage. if pipe empty, it doesn't return 0 for EOF, it just blocks
//boundary is important in both communications
//EPIPE means pipe broken, when reading end closes but parent tries to read for return -1
//Atomic means: when you write, it is guaranteed all is writen and no preamption happens


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int errno;
    int fd[2];
    int ret;
    ret = pipe(fd);
    int pid = fork();

    if(pid==0){

    }else if(pid > 0){
        
    }

}