#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

#define PATH "/home/xyy/stu/23.12.5/共享内存"
#define PROJ_ID 0x666//标识符

#define SIZE 4096