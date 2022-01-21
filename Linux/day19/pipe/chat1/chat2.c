#include <func.h>
//聊天2，先打开1号管道的写端，再打开2号管道的读端
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,3)
    int fdr,fdw;
    fdw=open(argv[1],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open1")
    fdr=open(argv[2],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open2")
    printf("I am chat2\n");
    //聊天
    char buf[128]={0};
    while(1)
    {
        //先读对方发过来的数据
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));
        printf("get=%s\n",buf);
        //再讲话
        memset(buf,0,sizeof(buf));
        read(STDIN_FILENO,buf,sizeof(buf));
        write(fdw,buf,strlen(buf)-1);
    }
    close(fdr);
    close(fdw);
    return 0;
}