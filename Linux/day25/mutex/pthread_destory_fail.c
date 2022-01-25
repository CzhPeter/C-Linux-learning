#include <func.h>

int main()
{
    pthread_mutex_t mutex;
    int ret=pthread_mutex_init(&mutex,NULL);
    THREAD_ERR_CHECK(ret,"pthread_mutex_init")
    pthread_mutex_lock(&mutex);
    ret=pthread_mutex_destroy(&mutex);//销毁锁
    THREAD_ERR_CHECK(ret,"pthread_mutex_destory")
    return 0;
}