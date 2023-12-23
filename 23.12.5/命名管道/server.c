#include"common.h"

int main()
{
    umask(0);
    if(mkfifo(FILE,0666)<0)
    {
        perror("mkfifo");
        return 1;
    }
    int fd=open(FILE,O_RDONLY);
    if(fd<0)
    {
        perror("open");
        return 2;
    }
    char mes[128];
    while(1)
    {
        mes[0]='\0';
        ssize_t len=read(fd,mes,sizeof(mes)-1);
        if(len>0)
        {
            mes[len]='\0';
            printf("client:%s\n",mes);
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
    return 0;
}