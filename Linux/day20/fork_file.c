#include <func.h>

//创建子进程，文件的共享情况
int main()
{
    pid_t pid;
    int fd=open("file",O_RDWR);
    char buf[128]={0};
    pid=fork();
    if(0==pid)
    {
        //孩子的代码写这里
        read(fd,buf,5);
        printf("I am child,num=%s\n",buf);
        return 0;
    }
    else {
        //父亲的代码写这里
        read(fd,buf,5);
        printf("I am parent,num=%s\n",buf);
        sleep(1);
        return 0;
    }
}