#include <stdio.h>
#include <unistd.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    int ret;
    char buff[10];

    // ret = system("./a.out");
    
    // int r = sprintf(buff, "%d", ret);
    // write(STDOUT_FILENO, buff, r);
    
    int status = 0;
    int pid;

    
   pid = fork();
   
   if(pid==0){
       exit(256);
   }
    if(pid>0){
        int w = wait(&status);
        int r;
        //IFEXITED CHECK
        
         r = sprintf(buff, "%d", r);
        write(STDOUT_FILENO, buff, r);
    }else{
        perror("");
    }
   
    
    
    

    return 0;
}
//exit return status in one byte
//other three bytes in status is other information
