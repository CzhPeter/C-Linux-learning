#include <func.h>

//sigfunc是我们自定义的信号处理函数
void sigfunc(int signum)
{
    printf("sig %d is coming\n",signum);
}

int main()
{
    //提前设定好2号信号的信号处理行为
    if(SIG_ERR==signal(SIGINT,SIG_IGN))
    {
        printf("signal failed\n");
        return -1;
    }
    sleep(10);
    signal(SIGINT,SIG_DFL);
    while(1);
    return 0;
}