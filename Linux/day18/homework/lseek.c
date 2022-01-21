#include <func.h>

typedef struct student
{
    int num;
    char name[20];
    float score;
}stu,*pstu;

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2)
    stu buf[3]={{1001,"lele",92.30},{1002,"xiongda",95.60},{1003,"hanmeimei",93.50}};
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open")
    write(fd,buf,sizeof(buf));
    int ret;
    ret=lseek(fd,0,SEEK_SET);
    ERROR_CHECK(ret,-1,"lseek")
    memset(buf,0,sizeof(buf));
    read(fd,buf,sizeof(buf));
    int i;
    for(i=0;i<3;i++)
    {
        printf("num=%d,name=%s,score=%.2f\n",buf[i].num,buf[i].name,buf[i].score);
    }
    close(fd);
    return 0;
}