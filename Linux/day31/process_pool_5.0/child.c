#include "process_pool.h"

int make_child(process_data_t* p_manage,int process_num)
{
    int i;
    pid_t pid;
    int fds[2];//与子进程之间的管道
    int ret;
    for(i=0;i<process_num;i++)
    {
        ret=socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
        ERROR_CHECK(ret,-1,"socketpair")
        pid=fork();
        if(0==pid)
        {
            close(fds[1]);
            child_handle(fds[0]);//一定要让子进程在child_handle内exit
        }
        close(fds[0]);
        //父进程通过fds[1]和子进程进行通信，和pipe的区别是fds[1]是既可以读也可以写
        p_manage[i].pid=pid;
        p_manage[i].fd=fds[1];
        p_manage[i].busy=0;//默认子进程是非忙碌状态
#ifdef DEBUG
        printf("p_manage[%d].fd=%d\n",i,p_manage[i].fd);
#endif
    }
}

int child_handle(int fd)
{
    int new_fd,ret;//子进程要接收一个new_fd，通过new_fd给对应的客户端发文件
    char flag=1;
    while(1)
    {
        recv_fd(fd,&new_fd);//接收任务
        printf("gets task,new_fd=%d\n",new_fd);
        trans_file(new_fd);//给客户端发文件
        close(new_fd);
        write(fd,&flag,sizeof(flag));//通知父进程完成任务
    }
}