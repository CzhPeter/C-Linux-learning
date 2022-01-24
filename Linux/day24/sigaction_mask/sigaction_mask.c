#include <func.h>

void sigfunc(int signum,siginfo_t *p,void *p1)
{
    printf("before sleep,sig %d is coming\n",signum);
    sleep(3);
    printf("after sleep,sig %d is coming\n",signum);
}

//等2号信号执行完才响应3号信号
int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));
    act.sa_sigaction=sigfunc;
    act.sa_flags=SA_SIGINFO;
    sigemptyset(&act.sa_mask);//清空掩码集合
    sigaddset(&act.sa_mask,SIGQUIT);//填入3号信号，2号信号处理流程中就不会被3号打断
    int ret=sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction")
    while(1);
    return 0;
}