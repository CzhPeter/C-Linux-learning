#include <func.h>

//没有应用场景，理解忽略
int main()
{
    signal(SIGINT,SIG_IGN);
    sleep(5);
    sigset_t pending;
    sigemptyset(&pending);
    sigpending(&pending);
    if(sigismember(&pending,SIGINT))
    {
        printf("SIGINT is pending\n");
    }else{
        printf("SIGINT is not pending\n");
    }
    printf("you can see me\n");
    return 0;
}