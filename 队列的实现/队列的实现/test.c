#define _CRT_SECURE_NO_WARNINGS 1 

#include"Queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d\n", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d\n", QueueSize(&q));
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	printf("%d\n", QueueSize(&q));

	QueueDestory(&q);
}

int main()
{
	test1();


	return 0;
}
