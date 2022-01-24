#include <func.h>

struct MSG{
    long mtype;
    char buf[64];
};

int main()
{
    int msgid=msgget(1000,IPC_CREAT|0600);//创建消息队列
    ERROR_CHECK(msgid,-1,"mesgget")
    struct MSG msg;
    bzero(&msg,sizeof(msg));
    int ret=msgrcv(msgid,&msg,sizeof(msg),0,0);
    ERROR_CHECK(ret,-1,"msgrcv")
    printf("get msg=%s\n",msg.buf);
    return 0;
}