#include"comm.h"

int main()
{
    key_t key=ftok(PATH,PROJ_ID);
    if(key<0)
    {
        perror("ftok");
        return 1;
    }

    int shm=shmget(key,SIZE,IPC_CREAT);
    if(shm<0)
    {
        perror("shmget");
        return 2;
    }

    printf("key:%x\n",key);
    printf("shm:%d\n",shm);

    char* mem=shmat(shm,NULL,0);
    if(mem==(void*)-1)
    {
        perror("shmat");
        return 3;
    }

    int i=0;
    int seconds=26;
    mem[0]='\0';
    while(seconds--)
    {
        mem[i++]='A'+i-1;
        mem[i]='\0';
        sleep(1);
    }

    shmdt(mem);
    return 0;
}