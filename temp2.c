#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signo){
        write(STDOUT_FILENO, "HI",2);

}
// int main(){
//     signal(SIGINT, signal_handler);

//     char buff[50];
//     int t = read(STDIN_FILENO, buff, 50);
// write(STDOUT_FILENO, buff, t);


// }
void sc_handler(int signo){
    write(STDOUT_FILENO, "hi",2);
}

int main(){
    int pid;
    char buff[20];
    int status = 0;
    signal(SIGCHLD, sc_handler);
    
    pid = fork();
    
    if(pid == 0){
        // while(1){

        // }
    }else if(pid > 0){
        
        int ppid  = getppid();
        printf("%d", ppid);
        wait(&status);
    }else{
        printf("error");
    }
}

//how do you prove donon independ cheezein.. waitpid and signals