#include <func.h>

int main()
{
    int shmid;
    shmid=shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget")
    printf("shmid=%d\n",shmid);
    char *p=shmat(shmid,NULL,0);//共享内存连接到本进程内
    ERROR_CHECK(p,(char*)-1,"shmat")
    sleep(30);
}