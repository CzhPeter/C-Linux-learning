#include <func.h>

int main()
{
    int fds[2];//数组
    pipe(fds);//初始化一条无名管道，fds[0]读端，fds[1]写端
    if(!fork())
    {
        close(fds[1]);
        //孩子读
        char buf[128]={0};
        read(fds[0],buf,sizeof(buf));//管道没数据会阻塞
        printf("I am child, get=%s\n",buf);
        return 0;
    }else{
        close(fds[0]);
        //父亲写
        sleep(3);
        write(fds[1],"hello",5);
        wait(NULL);
        return 0;
    }
}