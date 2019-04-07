#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// static void signal_handler(int signo){
//         write(STDOUT_FILENO, "HI",2);

// }
// int main(){
//     if(signal(SIGINT, signal_handler)==SIG_ERR){
//         write(STDOUT_FILENO, "Error in signal",15);
        
//     }
//     char buff[50];
//     read(STDIN_FILENO, buff, 50);


// }
void sc_handler(){
    write(STDOUT_FILENO, "hi",2);
}

int main(){
    int pid;
    char buff[20];
    
    signal(SIGCHLD, sc_handler);
    
    pid = fork();
    
    if(pid == 0){
        execlp("gedit", "gedit", NULL);
    }else if(pid > 0){
        
        while(1){

        }
    }
}

//how do you prove donon independ cheezein.. waitpid and signals