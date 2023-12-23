#include"common.h"

int main()
{
    int fd=open(FILE,O_WRONLY);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    char mes[128];
    while(1)
    {
        mes[0]='\0';
        printf("please Export:");
        fflush(stdout);
        ssize_t len=read(0,mes,sizeof(mes)-1);
        if(len>0)
        {
            mes[len-1]='\0';
            write(fd,mes,strlen(mes));
        }
    }
    close(fd);
    return 0;
}