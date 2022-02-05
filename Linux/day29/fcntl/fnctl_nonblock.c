#include <func.h>

int fcntl_nonblock(int fd)
{
    int status=fcntl(fd,F_GETFL);//拿出标准输入所有的属性
    status=status|O_NONBLOCK;//修改其为非阻塞
    int ret=fcntl(fd,F_SETFL,status);
    ERROR_CHECK(ret,-1,"fcntl")
}

//修改标准输入为非阻塞
int main()
{
    sleep(5);
    char buf[128]={0};
    fcntl_nonblock(STDIN_FILENO);
    int ret=read(STDIN_FILENO,buf,sizeof(buf));
    ERROR_CHECK(ret,-1,"read")
    printf("ret=%d, buf=%s errno=%d\n",ret,buf,errno);
    return 0;
}