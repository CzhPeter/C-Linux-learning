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
    msg.mtype=1;
    strcpy(msg.buf,"hello");
    int ret=msgsnd(msgid,&msg,sizeof(msg.buf),0);//发送消息
    ERROR_CHECK(ret,-1,"msgsnd")
    return 0;
}