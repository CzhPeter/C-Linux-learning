#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open")
    printf("\n");//刷新标准输出
    close(STDOUT_FILENO);
    int fd1=dup(fd);//dup复制放置的位置是没有使用的文件描述符的最小编号
    printf("helloworld\n");
    close(fd);
    close(fd1);
    return 0;
}