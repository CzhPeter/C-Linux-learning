#include <func.h>

int main()
{
    int msgid=msgget(1000,IPC_CREAT|0600);//创建消息队列
    ERROR_CHECK(msgid,-1,"mesgget")
    return 0;
}