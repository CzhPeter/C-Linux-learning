#include <func.h>

void* pthread_func(void *p)
{
    while(1);
    return NULL;
}

//创建子线程后，cancel子线程，子线程执行while(1)
int main()
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,pthread_func,NULL);
    THREAD_ERR_CHECK(ret,"pthread_create")
    //发送cancel给子线程，cancel执行成功不代表子线程被cancel掉了，只表示该请求成功发送
    ret=pthread_cancel(pthid);
    THREAD_ERR_CHECK(ret,"pthread_cancel")
    ret=pthread_join(pthid,NULL);
    THREAD_ERR_CHECK(ret,"pthread_join")
    printf("I am main thread\n");
    return 0;
}