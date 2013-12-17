#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    int sockfd;
    char *str;
    char buf[100];
    int n;
    
    str = (char *)malloc(100);
    str = argv[1];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "10.13.29.165", &servaddr.sin_addr);
    servaddr.sin_port = htons(9000);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    write(sockfd, str, strlen(str));
    n = read(sockfd, buf, 100);
    write(STDOUT_FILENO, buf, n);

    close(sockfd);
    return 0;
} 
