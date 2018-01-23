#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    int fds[2];
    char str1[] = "Who are you?";
    char str2[] = "I am your father";
    char buf[BUF_SIZE];
    pid_t pid;
    //创建管道
    pipe(fds);
    //创建子进程
    pid = fork();
    if (pid == 0) //子进程复制的并非管道，而是文件描述符
    {
        //将str1写入管道
        write(fds[1], str1, sizeof(str1));
        sleep(2);
        read(fds[0], buf, BUF_SIZE);
        printf("Child proc output: %s \n", buf);
    } else {
        read(fds[0], buf, BUF_SIZE);
        printf("Parent proc output: %s \n", buf);
        write(fds[1], str2, sizeof(str2));
        sleep(3);//等待子进程输出完毕后再退出
    }
    return 0;
}