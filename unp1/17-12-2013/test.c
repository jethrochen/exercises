#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;
    
    if ((pid = fork()) == 0)
    {
        execlp("gnome-terminal", "gnome-termianl", (char *)0);
        printf("hello\n");
    }

    sleep(100);
    return 0;
}
