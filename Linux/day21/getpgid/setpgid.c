#include <func.h>

//获取进程组id
int main()
{
    if(!fork())
    {
        setpgid(0,0);//让子进程独立成为一个进程组
        printf("I am child,pid=%d,ppid=%d,pgid=%d\n",getpid(),getppid(),getpgid(0));//getpgid()中参数为0时查看当前进程的pgid
        while(1);
        return 0;
    }else{
        printf("I am parent,pid=%d,ppid=%d,pgid=%d\n",getpid(),getppid(),getpgid(0));
        while(1);
        return 0;
    }
}