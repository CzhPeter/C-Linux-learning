#include <func.h>
//关闭文件后，文件不能被再次读取
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open")
    printf("fd=%d\n",fd);
    int fd1=fd;
    close(fd);
    char buf[1024]={0};
    int ret;
    ret=read(fd1,buf,sizeof(buf));
    ERROR_CHECK(ret,-1,"read")
    printf("%s",buf);
    close(fd1);
    return 0;
}