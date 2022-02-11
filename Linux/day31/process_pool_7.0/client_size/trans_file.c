#include "func.h"

//循环接收数据，直到接收到自己想要的数量
int recv_n(int sfd,void* buf,int data_len)
{
    char* p=(char*)buf;
    int total=0,ret;
    while(total<data_len)
    {
        ret=recv(sfd,p+total,data_len-total,0);
        if(0==ret)//对端断开
        {
            return -1;
        }
        total+=ret;
    }
    return 0;
}

//循环发送数据，直到发送了自己想要的数量
int send_n(int sfd,void* buf,int data_len)
{
    char* p=(char*)buf;
    int total=0,ret;
    while(total<data_len)
    {
        ret=send(sfd,p+total,data_len-total,0);
        total+=ret;
    }
    return 0;
}

//显示接收进度的recv_n
int recv_n_show(int sfd,void* buf,int data_len)
{
    char* p=(char*)buf;
    int total=0,ret;
    off_t slice_size=data_len/10000;//文件大小的万分之一(0.01%)
    off_t last_size=0;//上一次大小
    while(total<data_len)
    {
        ret=recv(sfd,p+total,data_len-total,0);
        if(0==ret)//对端断开
        {
            return -1;
        }
        total+=ret;
        if(total-last_size>slice_size)//打印进度
        {
            printf("%6.2lf%%\r",(double)total/data_len*100);
            fflush(stdout);
            last_size=total;
        }
    }
    printf("100.00%%\n");
    return 0;
}