#define _CRT_SECURE_NO_WARNINGS 1 

#include"stack.h"

void StactInit(ST* p)
{
	assert(p);
	p->a = (Datetype*)malloc(sizeof(Datetype) * 2);
	p->capacity = 2;
	p->top = 0;
}
void StackDestory(ST* p)
{
	assert(p);
	free(p->a);
	p->a = NULL;
	p->top = p->capacity = 0;
}
void StackPush(ST* p, Datetype x)
{
	assert(p);
	if (p->top == p->capacity)
	{
		Datetype* temp = (Datetype*)realloc(p->a, p->capacity * 2 * sizeof(Datetype));
		if (temp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		else
		{
			p->a = temp;
			p->capacity *= 2;
		}
	}
	p->a[p->top] = x;
	p->top++;
}
void StackPop(ST* p)
{
	assert(p);

	assert(p->top > 0);
	p->top--;
}
Datetype StackTop(ST* p)
{
	assert(p);
	assert(p->top > 0);

	return p->a[p->top - 1];
}
int StackSize(ST* p)
{
	assert(p);

	return p->top;
}
int StackEmpty(ST* p)
{
	assert(p);
	if (p->top)
	{
		return 0;//p->top不为0返回0
	}
	return 1;//p->top为0返回1
}