#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2)
    int fd;
    fd=open(argv[1],O_WRONLY);
    ERROR_CHECK(fd,-1,"open")
    printf("I am writer\n");
    write(fd,"hello",5);//写不阻塞
    close(fd);
    return 0;
}