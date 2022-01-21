#include <func.h>

int main()
{
    int fds[2];//数组
    pipe(fds);//初始化一条无名管道，fds[0]读端，fds[1]写端
    if(!fork())
    {
        close(fds[0]);
        //孩子写
        write(fds[1],"Hello",5);
        return 0;
    }else{
        close(fds[1]);
        //父亲读
        sleep(3);
        char buf[128]={0};
        read(fds[0],buf,sizeof(buf));//管道没数据会阻塞
        printf("I am parent, get=%s\n",buf);
        wait(NULL);
        return 0;
    }
}