#include <func.h>
//使用epoll实现即时聊天
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
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
    //编写即时聊天
    char buf[128]={0};
    int epfd=epoll_create(1);//得到一个epoll的句柄，也可叫epoll的描述符
    struct epoll_event event,evs[2];
    //先注册标准输入
    event.data.fd=STDIN_FILENO;
    event.events=EPOLLIN;//监控是否可读
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl")
    //再注册new_fd
    event.data.fd=new_fd;
    event.events=EPOLLIN;//监控是否可读
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl1")
    int ready_fd_num,i;
    while(1)
    {
        //监控哪一个描述符就绪，epoll就会返回
        ready_fd_num=epoll_wait(epfd,evs,2,-1);
        // printf("test evi[i].data.fd=%d\n",evs[0].data.fd);
        for(i=0;i<ready_fd_num;i++)
        {
            if(evs[i].data.fd==STDIN_FILENO)//如果标准输入可读
            {
                //服务器发送数据
                bzero(buf,sizeof(buf));
                ret=read(STDIN_FILENO,buf,sizeof(buf));
                if(!ret)
                {
                    printf("I want to go\n");
                    return 0;
                }
                send(new_fd,buf,strlen(buf)-1,0);
            }
            if(evs[i].data.fd==new_fd)//如果new_fd可读
            {
                bzero(buf,sizeof(buf));
                //服务器接收数据
                ret=recv(new_fd,buf,sizeof(buf),0);
                ERROR_CHECK(ret,-1,"recv")
                if(!ret)//对方断开
                {
                    printf("byebye\n");
                    return 0;
                }
                printf("gets: %s\n",buf);
            }
        }
    }
    close(new_fd);//关闭对应描述符
    close(sfd);
    return 0;
}