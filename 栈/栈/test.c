#define _CRT_SECURE_NO_WARNINGS 1 

#include"stack.h"

int main()
{
	ST s;
	StactInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");

	StackDestory(&s);
	return 0;
}