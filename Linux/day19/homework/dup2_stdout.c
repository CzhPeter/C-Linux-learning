#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open")
    printf("\n");//刷新标准输出
    int fd1=dup2(fd,STDOUT_FILENO);//dup2第二参数是指要复制到什么位置
    printf("fd1=%d\n",fd1);
    printf("helloworld\n");
    close(fd);
    close(fd1);
    return 0;
}