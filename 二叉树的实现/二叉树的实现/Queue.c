#define _CRT_SECURE_NO_WARNINGS 1 

#include"Queue.h"

void QueueInit(Queue* p)
{
	assert(p);
	p->head = NULL;
	p->tail = NULL;
	p->size = 0;
}

void QueueDestory(Queue* p)
{
	assert(p);
	QN* cur = p->head;
	while (cur)
	{
		QN* next = cur->next;
		free(cur);
		cur = next;
	}
	p->head = NULL;
	p->tail = NULL;
	p->size = 0;
}

void QueuePush(Queue* p, QDataType x)
{
	assert(p);
	QN* newnode = (QN*)malloc(sizeof(QN));
	newnode->val = x;
	newnode->next = NULL;
	if (p->tail == NULL)
	{
		p->head = p->tail = newnode;
	}
	else
	{
		p->tail->next = newnode;
		p->tail = newnode;
	}
	p->size++;
}

void QueuePop(Queue* p)
{
	assert(p);
	assert(p->size > 0);

	if (p->head->next == NULL)//删除到只剩一个节点
	{
		free(p->head);
		p->head = p->tail = NULL;//需要把p->tail置空，否则
	}
	else//多个节点删除
	{
		QN* next = p->head->next;
		free(p->head);
		p->head = next;
	}
	p->size--;
}

QDataType QueueFront(Queue* p)
{
	assert(p);
	assert(p->head);

	return p->head->val;
}

QDataType QueueBack(Queue* p)
{
	assert(p);
	assert(p->head);

	return p->tail->val;
}

int QueueEmpty(Queue* p)
{
	assert(p);

	if (p->head)
	{
		return 1;//非空返回1；
	}
	return 0;//空返回0；
}

int QueueSize(Queue* p)
{
	assert(p);

	return p->size;
}