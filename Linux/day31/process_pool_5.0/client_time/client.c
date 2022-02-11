#include "func.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int sfd;
    sfd=socket(AF_INET,SOCK_STREAM,0);//初始化一个网络描述符，对应了一个缓冲区
    ERROR_CHECK(sfd,-1,"socket")
    printf("sfd=%d\n",sfd);
    struct sockaddr_in ser_addr;
    bzero(&ser_addr,sizeof(ser_addr));//清空
    ser_addr.sin_family=AF_INET;//进行ipv4通信
    ser_addr.sin_addr.s_addr=inet_addr(argv[1]);//把ip的点分十进制转为网络字节序
    ser_addr.sin_port=htons(atoi(argv[2]));//把端口转为网络字节序
    //客户端去连接服务器
    int ret=connect(sfd,(struct sockaddr*)&ser_addr,sizeof(ser_addr));
    ERROR_CHECK(ret,-1,"connect")
    //接收文件名
    int data_len;
    char buf[1000]={0};
    recv_n(sfd,&data_len,4);//接收文件名长度
    recv_n(sfd,buf,data_len);//接收文件名
    int fd=open(buf,O_WRONLY|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open")
    //接文件大小
    recv_n(sfd,&data_len,4);
    //download_size是当前大小
    off_t file_size,download_size=0;
    recv_n(sfd,&file_size,data_len);
    //接收文件内容
    time_t now,last_time;
    now=last_time=time(NULL);
    while(1)
    {
        recv_n(sfd,&data_len,4);//接文件内容长度
        if(data_len>0)
        {
            recv_n(sfd,buf,data_len);//接文件内容
            write(fd,buf,data_len);//把文件内容写到文件里
            download_size+=data_len;
            now=time(NULL);
            if(now>last_time)//打印进度
            {
                printf("%6.2lf%%\r",(double)download_size/file_size*100);
                fflush(stdout);
                last_time=now;
            }
        }else{
            printf("100.00%%\n");
            break;
        }    
    }
    close(fd);
    close(sfd);//关闭对应描述符
    return 0;
}