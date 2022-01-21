#include <func.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        //孩子的代码写这里
        printf("I am child,pid=%d,ppid=%d\n",getpid(),getppid());
        exit(3);
    }
    else {
        //父亲的代码写这里
        printf("I am parent,mychild=%d,pid=%d,ppif=%d",pid,getpid(),getppid());
        int status;
        pid=wait(&status);
        if(WIFEXITED(status))
        {
            printf("child exit code=%d\n",WEXITSTATUS(status));
            printf("%d\n",status);
            printf("%d\n",WIFEXITED(status));
        }
        else{
            printf("child crash\n");
        }
        printf("wait pid=%d\n",pid);
        return 0;
    }
}