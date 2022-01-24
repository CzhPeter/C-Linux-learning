#include <func.h>

//p=q
void* pthread_func(void *p)
{
    strcpy(p,"hello");//子线程给空间中放一个hello
    printf("I am child thread\n");
}

//pthread_create给子线程传递参数
int main()
{
    pthread_t pthid;
    char *q=(char*)malloc(100);
    int ret=pthread_create(&pthid,NULL,pthread_func,q);
    if(ret!=0)
    {
        printf("pthread_create failed\n");
        return -1;
    }
    usleep(1);
    printf("I am main thread\n");
    printf("gets %s\n",q);
    return 0;
}