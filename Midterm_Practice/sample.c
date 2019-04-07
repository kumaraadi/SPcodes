#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char **argv){
    write(STDOUT_FILENO, "new\n", 4);
}