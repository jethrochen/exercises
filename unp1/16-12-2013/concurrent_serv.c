#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(void)
{
    pid_t pid;
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr, storeaddr;
    char buf[200];
    char str[200];
    time_t ticks;
    socklen_t len;
    int i, n;
    int listen_d, accept_d;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(0);

    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    len = sizeof(storeaddr);
    getsockname(listenfd, (struct sockaddr*)&storeaddr, &len);
    inet_ntop(AF_INET, &storeaddr.sin_addr, str, sizeof(str));
    printf("local address %s, port %d\n", str, ntohs(storeaddr.sin_port));
    listen_d = listen(listenfd, 20);
    printf("listen return %d\n", listen_d);

    for (;;)
    {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
        if ((pid = fork()) == 0)
        {
            close(listenfd);
            n = read(connfd, buf, 200);
            inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(buf));
            printf("recieved from %s, port %d: %s\n", str,
                    ntohs(cliaddr.sin_port), buf);
            for (i = 0; i < n; ++i)
                buf[i] = toupper(buf[i]);
            write(connfd, buf, n);
            close(connfd);
            exit(0);
        }
        close(connfd);
    }
}

