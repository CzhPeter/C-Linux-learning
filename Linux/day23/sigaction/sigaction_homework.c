#include <func.h>

void sigfunc(int signum,siginfo_t *p,void *p1)
{
    printf("before sleep,sig %d is coming\n",signum);
    sleep(3);
    printf("after sleep,sig %d is coming\n",signum);
}
int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));
    act.sa_sigaction=sigfunc;
    act.sa_flags=SA_SIGINFO|SA_NODEFER;
    int ret=sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction")
    ret=sigaction(SIGQUIT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction1")
    while(1);
    return 0;
}