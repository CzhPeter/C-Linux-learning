#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_RDONLY);
    ERROR_CHECK(fd,-1,"open")
    printf("I am reader\n");
    //读端读
    char buf[128]={0};
    read(fd,buf,sizeof(buf));//管道没数据就会阻塞
    printf("reader=%s\n",buf);
    close(fd);
    return 0;
}