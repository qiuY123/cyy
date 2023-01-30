#define _CRT_SECURE_NO_WARNINGS 1 

#include"stack.h"

void test1()
{
	St st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	printf("%d\n", StackSize(&st));
	while (StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
	printf("%d\n", StackSize(&st));
	StackDestory(&st);
}

int main()
{
	test1();


	return 0;
}