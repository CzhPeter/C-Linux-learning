#include <func.h>

typedef struct{
    int tickets;
    pthread_mutex_t mutex;
}data_t;

//两个子线程卖票
//窗口1买票
void* sale_windows1(void* p)
{
    int i;
    data_t* d=(data_t*)p;
    while(1)
    {
        pthread_mutex_lock(&d->mutex);
        if(d->tickets>0)//先加锁后读票数
        {
            printf("windows1 start sale %d\n",d->tickets);
            sleep(3);
            d->tickets--;
            pthread_mutex_unlock(&d->mutex);
            printf("windows1 finish sale %d\n",d->tickets);
        }else{
            pthread_mutex_unlock(&d->mutex);
            pthread_exit(NULL);
        }
        sleep(1);
    }
}

//窗口2买票
void* sale_windows2(void* p)
{
    int i;
    data_t* d=(data_t*)p;
    while(1)
    {
        pthread_mutex_lock(&d->mutex);
        if(d->tickets>0)//先加锁后读票数
        {
            printf("windows2 start sale %d\n",d->tickets);
            d->tickets--;
            pthread_mutex_unlock(&d->mutex);
            printf("windows2 finish sale %d\n",d->tickets);
        }else{
            pthread_mutex_unlock(&d->mutex);
            pthread_exit(NULL);
        }
        sleep(1);
    }
}

int main()
{
    data_t d;
    d.tickets=20;
    int ret=pthread_mutex_init(&d.mutex,NULL);//初始化锁
    THREAD_ERR_CHECK(ret,"pthread_mutes_init");
    pthread_t pthid[2];
    ret=pthread_create(&pthid[0],NULL,sale_windows1,(void*)&d);
    THREAD_ERR_CHECK(ret,"pthread_create")
    ret=pthread_create(&pthid[1],NULL,sale_windows2,(void*)&d);
    THREAD_ERR_CHECK(ret,"pthread_create")
    for(int i=0;i<2;i++)
    {
        pthread_join(pthid[i],NULL);
    }
    printf("main thread tickets=%d\n",d.tickets);
    ret=pthread_mutex_destroy(&d.mutex);
    THREAD_ERR_CHECK(ret,"pthread_mutex_destroy")
    return 0;
}
