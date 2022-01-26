#include <func.h>

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}data_t;

void* thread_func(void* p)
{
    //子线程等待在对应的条件变量上
    printf("I am child, will wait\n");
    data_t *d=(data_t*)p;
    pthread_mutex_lock(&d->mutex);
    int ret=pthread_cond_wait(&d->cond,&d->mutex);//wait前后需要加解锁
    pthread_mutex_unlock(&d->mutex);
    printf("I am child, wakeup, wait ret=%d, start work\n",ret);
    pthread_exit(NULL);
}

int main()
{
    data_t d;
    int ret;
    ret=pthread_mutex_init(&d.mutex,NULL);
    THREAD_ERR_CHECK(ret,"pthread_mutex_init")
    ret=pthread_cond_init(&d.cond,NULL);
    THREAD_ERR_CHECK(ret,"pthread_cond_init")
    //创建子线程
    pthread_t pthid;
    pthread_create(&pthid,NULL,thread_func,&d);
    sleep(1);
    //唤醒
    ret=pthread_cond_signal(&d.cond);//signal像一个脉冲，让条件一瞬间成立，如果成立后才去排队，得不到唤醒
    THREAD_ERR_CHECK(ret,"pthread_cond_signal")
    //join并回收子线程
    ret=pthread_join(pthid,NULL);
    THREAD_ERR_CHECK(ret,"pthread_join")
    printf("I am main thread\n");
    return 0;
}