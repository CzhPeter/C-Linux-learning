#include <func.h>

int main()
{
    //创建一个信号量集合
    int sem_id=semget(1000,1,IPC_CREAT|0600);//0600：给pv操作读写权限
    ERROR_CHECK(sem_id,-1,"semget")
    int ret=semctl(sem_id,0,SETVAL,1);//给信号量的值初始化为1
    ERROR_CHECK(ret,-1,"semctl")
    //获取信号量设置的值
    ret=semctl(sem_id,0,GETVAL);
    printf("信号量的值=%d\n",ret);
    return 0;
}