#define _CRT_SECURE_NO_WARNINGS 1 

#include"LDList.h"

LDL* LDListInit()//初始化循环链表（创建哨兵位节点）
{
	LDL* guard = (LDL*)malloc(sizeof(LDL));
	if (guard == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	guard->val = -1;
	guard->prev = guard;
	guard->next = guard;
	
	return guard;
}

LDL* CreatreLDListNode(DataType x)//创建链表节点
{
	LDL* newnode = (LDL*)malloc(sizeof(LDL));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

void LDListDestroy(LDL* ph)//链表的销毁
{
	assert(ph);

	LDL* cur = ph->next;
	while (cur != ph)
	{
		LDL* next = cur->next;
		free(cur);
		cur = next;
	}
	free(ph);
}

void LDListPushBack(LDL* ph, DataType x)//尾插
{
	/*assert(ph);

	LDL* node = CreatreLDListNode(x);
	LDL* tail = ph->prev;

	node->next = ph;
	node->prev = tail;
	tail->next = node;
	ph->prev = node;*/

	LDListInsertBefore(ph, x);
}

void LDListPopBack(LDL* ph)//尾删
{
	/*assert(ph);
	assert(ph->next != ph);

	LDL* tail = ph->prev;

	tail->prev->next = ph;
	ph->prev = tail->prev;
	free(tail);
	tail = NULL;*/

	LDListErase(ph->prev);
}

void LDListPushFront(LDL* ph, DataType x)//头插
{
	/*assert(ph);

	LDL* node = CreatreLDListNode(x);
	LDL* front = ph->next;

	node->next = front;
	node->prev = ph;
	ph->next = node;
	front->prev = node;*/

	LDListInsertBefore(ph->next, x);
}

void LDListPopFront(LDL* ph)//头删
{
	/*assert(ph);
	assert(ph->next != ph);

	LDL* front = ph->next;

	front->next->prev = ph;
	ph->next = front->next;
	free(front);*/

	LDListErase(ph->next);
}

LDL* LDListFind(LDL* ph, DataType x)//查找节点
{
	assert(ph);

	LDL* cur = ph->next;
	while (cur != ph)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LDListInsertBefore(LDL* pos, DataType x)//插入节点
{
	assert(pos);

	LDL* node = CreatreLDListNode(x);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}

void LDListErase(LDL* pos)//删除节点
{
	assert(pos);

	LDL* posprev = pos->prev;
	LDL* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}

void LDListPrint(LDL* ph)//打印链表
{
	assert(ph);

	LDL* cur = ph->next;
	while (cur != ph)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}