#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "../common/function.h"
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;

    pid_t pid;
    struct sigaction act;
    socklen_t adr_sz;
    int str_len, state;
    char buf[BUF_SIZE];
    if (argc != 2) {
        printf("Usage : %s <port> \n", argv[0]);
        exit(1);
    }
    /*定义信号处理器*/
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);
    /*初始化socket*/
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
    /*绑定socket*/
    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind error");
    /*监听socket,并设置缓冲队列为5*/
    if (listen(serv_sock, 5) == -1)
        error_handling("listen error");
    
    while(1)
    {
        adr_sz = sizeof(clnt_adr);
        /*接受客户端请求并创建socket*/
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
        if (clnt_sock == -1)
            continue;
        else
            puts("new client connected..");
        /*创建子进程*/
        pid = fork();
        if (pid == -1)
        {
            close(clnt_sock);
            continue;
        }
        if (pid == 0) //子进程运行区域
        {
            /*关闭子进程中多余的服务器套接字*/
            close(serv_sock);
            /*读取传输过来的数据*/
            while((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0){
                write(clnt_sock, buf, str_len);
            }
            close(clnt_sock);
            puts("client disconnected...");
            return 0;
        } else 
            /*关闭主进程中多余的客户端套接字*/
            close(clnt_sock);    
    }
        close(serv_sock);
        return 0;
}