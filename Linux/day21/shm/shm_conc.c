#include <func.h>

#define NUM 10000000
int main()
{
    int shmid;
    shmid=shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget")
    printf("shmid=%d\n",shmid);
    int *p=shmat(shmid,NULL,0);//共享内存连接到本进程内
    ERROR_CHECK(p,(char*)-1,"shmat")
    p[0]=0;
    int i;
    //对内存操作产生了并发，没有加锁，造成结果不等于20000000
    if(!fork())
    {
        for(i=0;i<NUM;i++)
        {
            p[0]++;
        }
        return 0;
    }else{
        for(i=0;i<NUM;i++)
        {
            p[0]++;
        }
        wait(NULL);
        printf("p[0]=%d\n",p[0]);
        return 0;
    }
}