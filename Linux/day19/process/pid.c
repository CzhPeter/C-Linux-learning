#include <func.h>

int main()
{
    printf("pid:%d  ppid:%d\n",getpid(),getppid());
    printf("uid:%d  gid:%d  euid:%d  egid:%d\n",getuid(),getgid(),geteuid(),getegid());
    while(1);
    return 0;
}