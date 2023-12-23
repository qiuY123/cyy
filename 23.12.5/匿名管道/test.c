#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2]={0};
    if(pipe(fd)<0)
    {
        perror("pipe");
        return 1;
    }
    pid_t id=fork();
    if(id==0)//子进程关闭读端，只向匿名管道写数据
    {
        close(fd[0]);
        const char* mes="hello father,i am child...";
        int count=8;
        while(count--)
        {
            write(fd[1],mes,strlen(mes));
            sleep(1);
        }
        close(fd[1]);
        exit(0);
    }
    //父进程关闭写段，只向匿名管道读数据
    close(fd[1]);
    // char buff[64];
    // while(1)
    // {
    //     ssize_t len=read(fd[0],buff,sizeof(buff));
    //     if(len>0)
    //     {
    //         buff[len]='\0';
    //         //write(0,buff,strlen(buff));
    //         printf("child send to father:%s\n",buff);
    //     }
    //     else if(len==0)
    //     {
    //         printf("read file end\n");
    //         break;
    //     }
    //     else
    //     {
    //         printf("read error\n");
    //         break;
    //     }
    // }
    close(fd[0]);
    int status=0; 
    pid_t ret=waitpid(id,&status,0);
    if(ret>=0)
    {
        if(WIFEXITED(status))//正常退出
        {
            printf("exit code:%d\n",WEXITSTATUS(status));
        }
        else//被信号所杀
        {
            printf("killed by siganl:%d\n",status&0x7f);
        }
    }
    return 0;
}