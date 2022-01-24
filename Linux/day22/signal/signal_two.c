#include <func.h>

void sigfunc(int signum)
{
    printf("before sleep,sig %d is coming\n",signum);
    sleep(3);
    printf("after sleep,sig %d is coming\n",signum);
}

int main()
{
    signal(SIGINT,sigfunc);
    signal(SIGQUIT,sigfunc);//后面来的信号会把前面的打断
    while(1);
    return 0;
}