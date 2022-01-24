#include <func.h>

//一次设置1个信号量集合中的多个信号量的值
int main()
{
    //创建一个信号量集合
    int sem_id=semget(1000,2,IPC_CREAT|0600);//需删除已经创建的信号量集合后，才能成功将nsems参数设置为2
    ERROR_CHECK(sem_id,-1,"semget")
    unsigned short arr[2]={2,6};
    //给两个信号量同时赋值
    int ret=semctl(sem_id,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl")
    //获取信号量里面每一个信号量的值
    bzero(arr,sizeof(arr));
    ret=semctl(sem_id,0,GETALL,arr);
    ERROR_CHECK(ret,-1,"semctl")
    printf("信号量0的值=%d,信号量1的值=%d\n",arr[0],arr[1]);
    return 0;
}