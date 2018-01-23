#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    int fds[2];
    char str[] = "Who are you?";
    char buf[BUF_SIZE];
    pid_t pid;
    //创建管道
    pipe(fds);
    //创建子进程
    pid = fork();
    if (pid == 0) //子进程复制的并非管道，而是文件描述符
    {
        //将str写入管道入口fds[1]
        write(fds[1], str, sizeof(str));
    } else {
        //从管道出口fds[0]拿到数据
        read(fds[0], buf, BUF_SIZE);
        puts(buf);
    }
    return 0;
}