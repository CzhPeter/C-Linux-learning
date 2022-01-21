#include <func.h>
//聊天1，先打开1号管道的读端，再打开2号管道的写端
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,3)
    int fdr,fdw;
    fdr=open(argv[1],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open1")
    fdw=open(argv[2],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open2")
    printf("I am chat1\n");
    //select聊天
    char buf[128]={0};
    fd_set rdset;
    int ret;
    int ready_fdnum;
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        ready_fdnum=select(fdr+1,&rdset,NULL,NULL,NULL);//rdset是传入传出参数
        if(FD_ISSET(STDIN_FILENO,&rdset))//标准输入有数据
        {
            memset(buf,0,sizeof(buf));
            ret=read(STDIN_FILENO,buf,sizeof(buf));
            if(0==ret)
            {
                printf("I want to leave\n");
                break;
            }
            write(fdw,buf,strlen(buf)-1);
        }
        if(FD_ISSET(fdr,&rdset))
        {
            memset(buf,0,sizeof(buf));
            ret=read(fdr,buf,sizeof(buf));
            if(0==ret)
            {
                printf("byebye\n");
                break;
            }
            printf("get=%s\n",buf);
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}