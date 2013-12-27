#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    int sockfd;
    char *sendmsg;
    char *recvmsg;
    int n;

    recvmsg = malloc(100);
    sendmsg = malloc(100);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "10.13.29.165", &servaddr.sin_addr);
    servaddr.sin_port = htons(9000);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    while ((n = read(STDIN_FILENO, sendmsg, 100)) > 0)
    {
        write(sockfd, sendmsg, n);
        n = read(sockfd, recvmsg, 100);
        write(STDOUT_FILENO, recvmsg, n);
    }

    printf("before close\n");
    scanf("%d", &n);
    close(sockfd);
    free(recvmsg);
    free(sendmsg);
    return 0;
} 
