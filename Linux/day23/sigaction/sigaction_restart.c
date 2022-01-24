#include <func.h>

void sigfunc(int signum,siginfo_t *p,void *p1)
{
    printf("sig %d is coming\n",signum);
}

//使用SA_RESTART标志后，卡在系统调用时信号来了不会出错
int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));
    act.sa_sigaction=sigfunc;//把信号处理函数赋给sa_sigaction
    act.sa_flags=SA_SIGINFO|SA_RESTART;//SA_SIGINFO加上后，sa_sigaction信号处理函数生效
    int ret=sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction")
    char buf[100]={0};
    ret=read(STDIN_FILENO,buf,sizeof(buf));
    printf("ret=%d,buf=%s",ret,buf);
    return 0;
}