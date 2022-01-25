#include <func.h>

void* pthread_func(void *p)
{
    printf("传入数值=%ld\n",(long)p);
    pthread_exit((void*)2);
}

//pthread_join 去等待子进程
int main()
{
    pthread_t pthid;
    long i=1;
    int ret=pthread_create(&pthid,NULL,pthread_func,(void*)i);
    THREAD_ERR_CHECK(ret,"pthread_create")
    long thread_return;
    ret=pthread_join(pthid,(void**)&thread_return);
    THREAD_ERR_CHECK(ret,"pthread_join")
    printf("返回数值=%ld\n",thread_return);
    return 0;
}