#include <func.h>

int main()
{
    int shmid;
    shmid=shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget")
    printf("shmid=%d\n",shmid);
    char *p=shmat(shmid,NULL,0);//共享内存连接到本进程内
    ERROR_CHECK(p,(char*)-1,"shmat")
    if(!fork())
    {
        strcpy(p,"How are you");
        sleep(1);
        return 0;
    }else{
        wait(NULL);
        printf("%s\n",p);
        int ret=shmctl(shmid,IPC_RMID,NULL);
        ERROR_CHECK(ret,-1,"shmctl")
        return 0;
    }
}