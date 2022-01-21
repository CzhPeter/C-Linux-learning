#include <func.h>

void Daemon()
{
    if(fork())//创建子进程，父进程退出
    {
        exit(0);
    }
    setsid();//成立新会话
    chdir("/");//改变路径到根
    umask(0);//修改文件掩码
    int i;
    for(i=0;i<3;i++)
    {
        close(i);
    }
    return;
}

int main()
{
    Daemon();
    int fd,ret;
    char buf[128]="wohenshuai";
    fd=open("/tmp/log",O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open")
    while(1)
    {
        sleep(2);
        ret=write(fd,buf,strlen(buf));
        ERROR_CHECK(ret,-1,"write")
    }
    return 0;
}