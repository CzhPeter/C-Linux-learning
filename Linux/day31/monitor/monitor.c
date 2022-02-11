#include "func.h"

int main()
{
    while(1)
    {
        pid_t pid=fork();
        if(0==pid)
        {
            //子进程
            printf("I am task\n");
            //这里写task函数
            while(1);
            return 0;
        }else{
            int status;
            wait(&status);
            if(WIFEXITED(status))
            {
                exit(0);
            }else{
                printf("child crash, start again\n");
            }
        }
    }
}