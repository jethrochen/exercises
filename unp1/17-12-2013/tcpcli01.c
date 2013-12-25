#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITALIZER;

void *rdpth(char *msg)
{
    if (!msg)
        exit(1);
    while(1)
    {
        pthread_rwlock_rwlock(rwlock);
        msg = fgets(msg, sizeof(msg), stdin);
        
}
int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    int sockfd;
    char *sendmsg;
    char *recvmsg;
    char *str;
    char buf[100];
    int n;

    sendmsg = malloc(100);
    recvmsg = malloc(100);
    str     = malloc(100);

    str = argv[1];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "10.13.29.165", &servaddr.sin_addr);
    servaddr.sin_port = htons(9000);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if ((sendpid = fork()) < 0)
    {
        printf("fork error\n");
        exit(1);
    }
    else if (sendpid == 0)
    {
        execlp("gnome-ternimal", (char *)0);
        printf("hello\n");
    }
    write(sockfd, str, strlen(str));
    n = read(sockfd, buf, 100);
    write(STDOUT_FILENO, buf, n);

    close(sockfd);
    return 0;
} 
