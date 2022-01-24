#include <func.h>

void sigfunc(int signum,siginfo_t *p,void *p1)
{
    printf("before sleep,sig %d is coming,send pid=%d,send uid=%d\n",signum,p->si_pid,p->si_uid);
    sleep(3);
    //把内核中的pending信号集合从内核取出来
    sigset_t pending;
    sigpending(&pending);
    //判断3号信号是否在pending集合中
    if(sigismember(&pending,SIGQUIT))
    {
        printf("SIGQUIT is pending\n");
    }else{
        printf("SIGQUIT is not pending\n");
    }
    printf("after sleep,sig %d is coming\n",signum);
}

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