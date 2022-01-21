#include <func.h>

int getmode(mode_t x,char* mode)
{
    int i,j,count=0;
    char tmp;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(x&(1<<(8-count)))
            {
                switch(j)
                {
                    case 0:
                        tmp='r';
                        break;
                    case 1:
                        tmp='w';
                        break;
                    case 2:
                        tmp='x';
                        break;
                }
            }
            else {
                tmp='-';
            }
            mode[count]=tmp;
            count++;
        }
    }
    mode[count]=0;
    return 0;
}

char gettype(unsigned char x)
{
    switch(x)
    {
        case 1:
            return 'p';
        case 2:
            return 'c';
        case 4:
            return 'd';
        case 6:
            return 'b';
        case 8:
            return '-';
    }
}

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2)
    DIR* dir;
    dir=opendir(argv[1]);
    if(NULL==dir)
    {
        perror("opendir");
        return -1;
    }
    struct dirent *p;
    struct stat buf;
    char time[13];
    char mode[10];
    int ret;
    while((p=readdir(dir)))
    {
        if(strcmp(p->d_name,".")==0||strcmp(p->d_name,"..")==0)
        {
            continue;
        }
        ret=stat(p->d_name,&buf);
        getmode(buf.st_mode,mode);
        strncpy(time,ctime(&buf.st_mtime)+4,12);
        printf("%c%s %3ld %s %s %6ld %s %s\n",\
        gettype(p->d_type),mode,buf.st_nlink,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,buf.st_size,time,p->d_name);
    }
    closedir(dir);
    return 0;
}
