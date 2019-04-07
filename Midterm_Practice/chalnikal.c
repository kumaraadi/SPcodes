#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
extern int errno;

int main()
{
    char buff[50];
    while (1)
    {
        int ret = read(STDIN_FILENO, buff, 50);

        buff[ret - 1] = '\0';
        if(ret > 10){
            if(strcmp(buff, "chal nikal")==0){
                exit(1);
            }
        }
        int i;
        int count_spc = 0, count_word = 0;
        bool word = false;
        for (i = 0; i < ret - 1; i++)
        {
            if (buff[i] == ' ')
            {
                count_spc++;
                if (word)
                {
                    count_word++;
                    word = false;
                }
            }
            else
            {
                word = true;
            }
        }
        if (buff[ret - 2] != ' ')
        {
            count_word++;
        }
        char w[10];
        char c[10];

        int w_ret = sprintf(w, "words:%i\n", count_word);
        int c_ret = sprintf(c, "characters:%i\n", ret - 1 - count_spc);
        write(STDOUT_FILENO, w, w_ret);
        write(STDOUT_FILENO, c, c_ret);
    }
}