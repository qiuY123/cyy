#include"common.h"

int main()
{
    umask(0);
    if(mkfifo(FILE,0666)<0)
    {
        perror("mkfifo");
        return 1;//命名管道创建失败
    }
    int fd=open(FILE,O_RDONLY);
    if(fd<0)
    {
        perror("open");
        return 2;//命名管道打开失败
    }

    int fd1=open("file-copy.txt",O_WRONLY|O_CREAT,0666);
    if(fd1<0)
    {
        perror("open");
        return  3;//拷贝文件的创建失败
    }
    char mes[128];
    while(1)
    {
        mes[0]='\0';
        ssize_t len=read(fd,mes,sizeof(mes)-1);
        if(len>0)
        {
            write(fd1,mes,len);
        }
        else if(len==0)
        {
            printf("client quit!\n");
            break;
        }
        else
        {
            printf("read fail!\n");
            break;
        }
    }
    close(fd);
    close(fd1);
    return 0;
}