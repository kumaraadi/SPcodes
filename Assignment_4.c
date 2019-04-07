#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <string>

// typedef struct MyArray 
// {
// 	char string[50];
// } MyArray;
typedef struct MyProcesses 
{
	char name[50];
    int pid;
    int stime;
    int etime;
} MyProcesses;

int main()
{
    
    struct MyProcesses proc[30];
    bool check_exit = false;
    int size_of_buffer = 100;  //YOU CAN'T DO IT -> Make it use Define
    int token_count;
    char initial_display[100] = "Welcome!\n\n";
    char ask_input[2]=">";
    float result;
    char a = '0';
    int proc_count = 0;


    write(STDOUT_FILENO, initial_display, 10);
    
    while(!check_exit){
        
        result = 0;
        char buff[size_of_buffer];
        token_count = 1;
            write(STDOUT_FILENO, ask_input, 1);
            int input_count = read(STDIN_FILENO, buff, size_of_buffer); 
            for(int i = 0; i < input_count-2; i++)
            {
                if(buff[i] == ' ' && buff[i+1] != ' ') {
                    token_count++;
                }  
            }
            char *arr[token_count];
            char *token ;
            int k = 0;

            token = strtok(buff, " ");

            
            while( token != NULL ) {
               
                arr[k] = token;
                token = strtok(NULL, " ");
                k++;
            }
            
            
            if(strcmp(arr[0],"add") == 0){
                if(token_count > 0){ 
                    
                    
                    for(int i = 1; i < token_count; i++)
                    {
                            result = result + atof(arr[i]);
                    }
                    
                    write(STDOUT_FILENO, "Sum: ",5);
                    int s = sprintf(buff,"%f\n\n", result);
                    write(STDOUT_FILENO, buff, s);
                    result = -1;
                }else{
                    write(STDOUT_FILENO, "No number to add! Try again.\n",29);
                }

                
            }
                
            
            
            
            else if(strcmp(arr[0],"run") == 0){
                
                int pid = fork();
                proc[proc_count].pid = pid;
                strcpy(proc[proc_count].name, arr[1]);
                proc_count++;
                char str[20];
                strcpy(str, arr[1]);
	            if( pid == 0 ) {
		            execvp(str, NULL);
	            }

                
	    
            }

            else if(strcmp(arr[0],"exit") == 0){
                write(STDOUT_FILENO, "Bye",3);
                check_exit = true;
            }else{
               
                write(STDOUT_FILENO, "Invalid Command\n",16);
            }
			
    }
       return 0;
}