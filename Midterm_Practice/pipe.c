#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid;
    int p1[2];
    int p2[2];

    int r = pipe(p1);
    if (r == -1)
    {
        perror("p1");
        _exit(0);
    }

    r = pipe(p2);
    if (r == -1)
    {
        perror("p2");
        _exit(0);
    }

    write(p1[1], "Hi", 2);
    char buff[10];
    r = read(p1[0], buff, 10);
    write(STDOUT_FILENO, buff, r);
}