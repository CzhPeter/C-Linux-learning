#include "func.h"
#define SPLICE_F_MORE 4
#define SPLICE_F_MOVE 1

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
    //统计下载时间
    struct timeval start,end;
    gettimeofday(&start,NULL);
    //接收文件名
    int data_len;
    char buf[1000]={0};
    ret=recv_n(sfd,&data_len,4);//接收文件名长度
    SELFFUNC_ERR_CHECK(ret,"recv_n")
    ret=recv_n(sfd,buf,data_len);//接收文件名
    SELFFUNC_ERR_CHECK(ret,"recv_n")
    int fd=open(buf,O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open")
    //接文件大小
    ret=recv_n(sfd,&data_len,4);
    SELFFUNC_ERR_CHECK(ret,"recv_n")
    //file_size是文件大小
    off_t file_size;
    ret=recv_n(sfd,&file_size,data_len);
    SELFFUNC_ERR_CHECK(ret,"recv_n")
    //接收文件内容，使用splice
    int pipefd[2];
    pipe(pipefd);
    int splice_bytes;
    off_t total=0;
    while(total<file_size)
    {
        splice_bytes=splice(sfd,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE|SPLICE_F_MOVE);
        //assert(splice_bytes!=-1);
        ret=splice(pipefd[0],NULL,fd,NULL,splice_bytes,SPLICE_F_MORE|SPLICE_F_MOVE);
        //assert(ret!=-1);
        total+=ret;
    }
    gettimeofday(&end,NULL);
    printf("use time=%ld\n",(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
    close(fd);
    close(sfd);//关闭对应描述符
    return 0;
}