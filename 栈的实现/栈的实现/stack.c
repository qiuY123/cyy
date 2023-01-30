#define _CRT_SECURE_NO_WARNINGS 1 

#include"stack.h"

void StackInit(St* p)
{
	assert(p);

	p->a = NULL;
	p->capacity = p->size = 0;
}

void StackDestory(St* p)
{
	assert(p);

	free(p->a);
	p->a = NULL;
	p->capacity = p->size = 0;
}

void StackPush(St* p, DataType x)
{
	assert(p);

	if (p->capacity == p->size)
	{
		int newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		DataType* tmp = (DataType*)realloc(p->a, sizeof(DataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		p->a = tmp;
		p->capacity = newcapacity;
	}
	p->a[p->size] = x;
	p->size++;
}

void StackPop(St* p)
{
	assert(p);
	assert(p->size > 0);

	p->size--;
}

DataType StackTop(St* p)
{
	assert(p);
	assert(p->size >= 0);

	return p->a[p->size - 1];
}

int StackSize(St* p)
{
	assert(p);

	return p->size;
}

int StackEmpty(St* p)
{
	assert(p);

	if (p->size)
	{
		return 1;//不为空返回1
	}
	return 0;//为空返回0
}

