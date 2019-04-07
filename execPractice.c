#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    int fd = open("file.txt", O_RDWR | O_TRUNC);
    write(STDOUT_FILENO, "Input:",6);
    char buff[50];
    int read_count = 0;
    while(1){
        

        int pid = fork();

        if(pid>0){
            //ead_count = read(STDIN_FILENO, buff, 50);
            write(fd, "12", 2);
            write(1, "P",1);
        }else{
            write(1, "C",1);
            int fd2 = open("file.txt", O_RDWR );
            int filedata;
            int result = 0;
            int read_ret = 1;
            int temp;
            while(read_count!=0){
                
                read_ret = read(STDIN_FILENO, buff, 1);
                sscanf(buff, "%d", temp); //strtok
                write(STDOUT_FILENO, buff, read_ret);
                result = result + temp;
                
                
            }
            int ret_ = sprintf(buff, "%s", result);
            write(fd2, buff, ret_);
       
       
    }
    }
    

    
    
    

   
    

    
    //execlp("./newExec", "1","2","3","5", NULL);
    
    
}