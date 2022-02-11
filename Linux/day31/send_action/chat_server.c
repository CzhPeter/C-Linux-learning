#include <func.h>

void sigfunc(int signum)
{
    printf("%d is coming\n",signum);
}

//疯狂地发送数据
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    //捕捉SIGPIPE信号
    signal(SIGPIPE,sigfunc);
    int sfd;
    sfd=socket(AF_INET,SOCK_STREAM,0);//初始化一个网络描述符，对应了一个缓冲区
    ERROR_CHECK(sfd,-1,"socket")
    printf("sfd=%d\n",sfd);
    //在bind之前去执行setsockopt，设定端口重用
    int reuse=1,ret;
    ret=setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int));
    ERROR_CHECK(ret,-1,"setsocketopt")
    struct sockaddr_in ser_addr;
    bzero(&ser_addr,sizeof(ser_addr));//清空
    ser_addr.sin_family=AF_INET;//进行ipv4通信
    ser_addr.sin_addr.s_addr=inet_addr(argv[1]);//把ip的点分十进制转为网络字节序
    ser_addr.sin_port=htons(atoi(argv[2]));//把端口转为网络字节序
    //开始绑定
    ret=bind(sfd,(struct sockaddr*)&ser_addr,sizeof(ser_addr));
    ERROR_CHECK(ret,-1,"bind")
    //开始监听，端口开启
    ret=listen(sfd,10);
    ERROR_CHECK(ret,-1,"listen")
    int new_fd;//new_fd是和客户端进行交流的描述符
    struct sockaddr_in client_addr;
    bzero(&client_addr,sizeof(client_addr));
    socklen_t addr_len=sizeof(client_addr);
    //accept完成了3次握手，没有连接，accept会阻塞
    new_fd=accept(sfd,(struct sockaddr*)&client_addr,&addr_len);
    ERROR_CHECK(new_fd,-1,"accept")
    printf("client ip=%s,port=%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
    char buf[1000]={0};
    int total=0;
    //send也会阻塞
    while(1)
    {
        ret=send(new_fd,buf,sizeof(buf),0);
        if(-1==ret)
        {
            break;
        }
        total+=ret;
        printf("total=%d\n",total);
    }
    close(new_fd);//关闭对应描述符
    close(sfd);
    return 0;
}