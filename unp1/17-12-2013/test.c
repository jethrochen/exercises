#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char num[100];
    int i;

    for (i = 1; i < 100; i++)
    {
        num[i] = '0' + i;
    }
    num[99] = '\0';
    printf("%s\n", num);

    write(STDOUT_FILENO, num, 10);
    printf("\n");
    write(STDOUT_FILENO, num, 20);

    return 0;
}
