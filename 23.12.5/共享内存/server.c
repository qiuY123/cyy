#include"comm.h"

int main()
{   
    key_t key=ftok(PATH,PROJ_ID);//获得标识符,用于创建共享内存
    if(key<0)
    {
        perror("ftok");
        return 1;
    }

    int shm=shmget(key,SIZE,IPC_CREAT|IPC_EXCL|0666);//用key创建内存大小为size的共享内存，IPC_CREAT获得共享内存的句柄,但无法保证是否是新创建的
                                                //IPC_CREAT|IPC_EXCL如果系统中存在key的共享内存，则出错返回。如果返回成功，则一定是新创建的共享内存
                                                //调用失败返回-1，调用成功返回用户层标识符
    if(shm<0)
    {
        perror("shmget");
        return 2;
    }

    printf("key:%x\n",key);
    printf("shm:%d\n",shm);

    //void* shmat(int shmid,const void* shmaddr,int shmflg);
    //第一个参数
    //第二个参数是指定共享内存映射进程地址空间的某一地址，设置为null时，让内核自己设置地址
    //第三个参数是关联共享内存的属性，
    //SHM_RDONLY，关联后共享内存只进行 读 操作,
    //SHM_RND，若shmaddr不为null，则关联地址自动向下调整为SHMLBA的整数倍。
    //0，默认为读写操作
    char* mem=shmat(shm,NULL,0);//调用成功返回映射进程地址空间的起始地址，shmat调用失败，返回（void*）-1;
    if(mem==(void*)-1)
    {
        perror("shmat");
        return 3;
    }

    int prev=0;
    int count=0;
    while(1)
    {
        int cur=strlen(mem);

        if(cur==prev)
        {
            count++;
        }
        prev=cur;
        if(count==6)
        {
            break;
        }
        printf("client: %s\n",mem);
        sleep(1);
    }

    shmdt(mem);//去关联

    //int shmctl(int shmid,in cmd,struct shmid_ds* buf)
    //第一个参数是创建共享内存的标识符，
    //第二个参数是IPC_STAT获取共享内存关联值，此时buf作为输出型参数，
    //IPC_SET,在进程有足够权限下，将共享内存的关联值设置为buf所指的数据结构中的值
    //IPC_RMID删除共享内存
    shmctl(shm,IPC_RMID,NULL);//调用成功返回0，失败返回-1；

    return 0;
}

