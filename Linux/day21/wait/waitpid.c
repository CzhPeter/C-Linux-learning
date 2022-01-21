#include <func.h>

//waitpid等要等待的子进程
int main()
{
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        //子进程代码
        printf("I am child, pid=%d,ppid=%d\n",getpid(),getppid());
        sleep(1);
        exit(3);
    }else{
        //父进程代码
        printf("I am parent, mychild=%d,pid=%d,ppid=%d\n",pid,getpid(),getppid());
        int status;
        pid_t pid1=waitpid(pid,&status,WNOHANG);
        if(pid1>0)
        {
            if(WIFEXITED(status))//判断子进程是否正常退出
            {
                printf("child exit code=%d\n",WEXITSTATUS(status));
            }else{
                printf("child crash\n");
            }
            printf("wait pid=%d\n",pid);
        }else{
            printf("no exit child\n");
        }
        return 0;
    }
}