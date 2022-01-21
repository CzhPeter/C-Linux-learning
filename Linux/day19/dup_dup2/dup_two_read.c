#include <func.h>
//文件描述符复制
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open")
    printf("fd=%d\n",fd);
    int fd1=dup(fd);
    printf("fd1=%d\n",fd1);
    char buf[1024]={0};
    int ret;
    ret=read(fd,buf,5);//先用fd1读取5个字节
    ERROR_CHECK(ret,-1,"read")
    printf("%s\n",buf);
    printf("-------\n");
    //清理buf
    memset(buf,0,sizeof(buf));
    ret=read(fd1,buf,5);//再用fd1读取5个字节
    ERROR_CHECK(ret,-1,"read")
    printf("%s\n",buf);
    close(fd);
    close(fd1);
    return 0;
}