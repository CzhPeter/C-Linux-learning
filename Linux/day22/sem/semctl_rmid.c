#include <func.h>

//删除信号量集合
int main()
{
    int sem_id=semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(sem_id,-1,"semget")
    int ret=semctl(sem_id,0,IPC_RMID);
    ERROR_CHECK(ret,-1,"semctl")
    return 0;
}