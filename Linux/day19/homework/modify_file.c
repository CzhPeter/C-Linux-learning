#include <func.h>

int main()
{
    int fd;
    fd=open("file",O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    write(fd,"hello",5);
    close(fd);
    return 0;
}