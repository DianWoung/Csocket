#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
    int serv_sock;
    int clnt_sock;
    int str_len, i;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[BUF_SIZE];

    FILE *readfp;
    FILE *writefp;
    if (argc != 2)
    {
        printf("Usage : %s <por>\n",argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    // 创建socket
    if (serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    //调用bind函数，给套接字分配地址
    if(bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");
    //监听socket
    if(listen(serv_sock, 5) == -1)// 5表示连接请求等待的队列长度，此时服务端套接字完成
        error_handling("listen() error");
    
    clnt_addr_size = sizeof(clnt_addr);
    for(i = 0; i < 5; i++)
    {
    //接受请求
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    //accept函数从listen队列头部取一个连接请求与客户端建立连接，并返回创建的套接字文件描述符
    //如果队列为空，则不会返回，直到有新的连接进来
    if (clnt_sock == -1)
        error_handling("accept() error");
    else
        printf("Connected client %d \n", i+1);
    
    readfp = fdopen(clnt_sock, "r");
    writefp = fdopen(dup(clnt_sock), "w");
    while(!feof(readfp))
    {
        fgets(message,BUF_SIZE,readfp);
        printf("received message from client:%s\n",message);
        fputs(message, writefp);
        fflush(writefp);
    }

    shutdown(fileno(writefp), SHUT_WR);
    fclose(readfp);
    fclose(writefp);
    }
    close(serv_sock);
    return 0;

}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}