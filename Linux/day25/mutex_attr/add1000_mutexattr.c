#include <func.h>

#define N 20000000

typedef struct{
    int num;
    pthread_mutex_t mutex;
}data_t;

int main()
{
    int shmid;
    shmid=shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget")
    data_t *p=shmat(shmid,NULL,0);
    ERROR_CHECK(p,(data_t*)-1,"shmat")
    p->num=0;//假的值初始化
    pthread_mutexattr_t mutex_attr;//定义一个锁属性
    pthread_mutexattr_init(&mutex_attr);//初始化锁属性
    //把锁属性设置为可以在进程之间使用的
    pthread_mutexattr_setpshared(&mutex_attr,PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&p->mutex,&mutex_attr);
    int i;
    time_t start,end;
    start=time(NULL);
    if(!fork())
    {
        for(i=0;i<N;i++)
        {
            pthread_mutex_lock(&p->mutex);//加锁
            p->num+=1;
            pthread_mutex_unlock(&p->mutex);//解锁
        }
        return 0;
    }else{
        for(i=0;i<N;i++)
        {
            pthread_mutex_lock(&p->mutex);//加锁
            p->num+=1;
            pthread_mutex_unlock(&p->mutex);//解锁
        }
        wait(NULL);
        end=time(NULL);
        printf("p->num=%d,use time=%ld\n",p->num,end-start);
        return 0;
    }
    return 0;
}