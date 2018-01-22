#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig)
{
    if (sig == SIGALRM)
        puts("Time out");
    alarm(2);
}

int main(int argc, char *argv[])
{
    int i;
    //初始化sigaction结构体
    struct sigaction act;
    //赋值信号处理器函数
    act.sa_handler = timeout;
    //sa_mask的初始化
    sigemptyset(&act.sa_mask);
    //sa_flags初始化
    act.sa_flags = 0;
    //注册信号处理器
    sigaction(SIGALRM, &act, 0);
    alarm(2);

    for(i = 0; i < 3; i++)
    {
        puts("Waiting...");
        sleep(100);
    }
    return 0;
}