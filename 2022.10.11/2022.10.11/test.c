#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

#define SWAP(N) ((N&0xaaaaaaaa)>>1)+((N&0x55555555)<<1)

int main()
{
	int x = 10;
	int y = SWAP(x);

	printf("%d", y);
	return 0;
}


//#define OFFSETOF(struct_name,name) (int)&(((struct_name*)0)->name)
//
//
//struct student
//{
//	char name[20];
//	int age;
//	short a;
//	double b;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct student, name));
//	printf("%d\n", OFFSETOF(struct student, age));
//	printf("%d\n", OFFSETOF(struct student, a));
//	printf("%d\n", OFFSETOF(struct student, b));
//
//	return 0;
//}