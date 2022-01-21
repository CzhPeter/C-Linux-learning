#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    off_t ret;
    ret=lseek(fd,5,SEEK_SET);
    ERROR_CHECK(ret,-1,"lseek")
    write(fd,"xiongda",7);
    close(fd);
    return 0;
}