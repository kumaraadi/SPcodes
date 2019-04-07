#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv){
    int sum = 0;
    char * num = argv[1];
    int i = 1;
    
    while(argv[i] != NULL){
        sum = sum + atoi(argv[i]);
        i++;
    }
    


    printf("%d",sum);
    // write(3,"NewAnand\n",9);
    perror("Child");

}

//file position pointer in parent child, points at same object if not opened seperately.
//Saturday assignment: add/run/exit 
//class assignment: taking input in parent and adding and printing in child process - hint: open 
//two different files; one in child to maintain read and write pointer.