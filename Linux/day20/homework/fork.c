#include <func.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        //孩子的代码写这里
        printf("I am child,pid=%d,ppid=%d\n",getpid(),getppid());
        //while(1);
        return 0;
    }
    else {
        //父亲的代码写这里
        printf("I am parent,mychild=%d,pid=%d,ppif=%d",pid,getpid(),getppid());
        while(1);
        return 0;
    }
}