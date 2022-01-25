#include <func.h>

//清理函数
void cleanup(void *p)
{
    printf("I am cleanup %ld\n",(long)p);
}

void* pthread_func(void *p)
{
    pthread_cleanup_push(cleanup,(void*)1);
    pthread_cleanup_push(cleanup,(void*)2);
    sleep(1);
    pthread_cleanup_pop(0);//pop(1)清理函数并执行，pop(0)弹出清理函数不执行
    pthread_cleanup_pop(0);
    return NULL;
}

//创建子线程后，子进程先malloc空间，然后在free之前，被cancel掉
int main()
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,pthread_func,NULL);
    THREAD_ERR_CHECK(ret,"pthread_create")
    //cancel时，子线程并没有开始free对应的空间
    ret=pthread_cancel(pthid);
    THREAD_ERR_CHECK(ret,"pthread_cancel")
    ret=pthread_join(pthid,NULL);
    THREAD_ERR_CHECK(ret,"pthread_join")
    printf("I am main thread\n");
    return 0;
}