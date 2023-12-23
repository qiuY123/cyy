#include"common.h"

int main()
{
    int fd=open(FILE,O_WRONLY);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    int fd2=open("file.txt",O_RDONLY);
    if(fd2<0)
    {
        perror("open");
        return 2;
    }
    char mes[128];
    while(1)
    {
        ssize_t len=read(fd2,mes,sizeof(mes));
        if(len>0)
        {
            write(fd,mes,len);
        }
        else if(len==0)
        {
            printf("read end!\n");
            break;
        }
        else
        {
            printf("read error!\n");
            break;
        }
    }
    close(fd);
    close(fd2);
    return 0;
}