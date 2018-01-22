#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//定义信号处理器（超时处理器）
void timeout(int sig)
{
    if (sig == SIGALRM)
        puts("Time out");
    //每隔两秒发送SIGALRM信号    
    alarm(2);
}
//定义信号处理器（Ctrl+C处理器）
void keycontrol(int sig)
{
    if (sig == SIGINT)
        puts("CTRL+C pressed");
}

int main(int argc, char *argv[])
{
    int i;
    //注册信号及对应处理器
    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol);
    //预约两秒后发送Alarm信号
    alarm(2);

    for(i = 0; i < 3; i++){
        puts("Waiting...");
        sleep(100);
    }
    return 0;
}