#include <func.h>

void sigfunc(int signum,siginfo_t *p,void *p1)
{
    printf("sig %d is coming\n",signum);
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));
    act.sa_sigaction=sigfunc;//把信号处理函数赋给sa_sigaction
    act.sa_flags=SA_SIGINFO|SA_RESETHAND;//SA_SIGINFO加上后，sa_sigaction信号处理函数生效
    int ret=sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction")
    while(1);
    return 0;
}