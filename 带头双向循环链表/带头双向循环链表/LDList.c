#define _CRT_SECURE_NO_WARNINGS 1 

#include"LDList.h"

LDL* LDListInit()//��ʼ��ѭ�����������ڱ�λ�ڵ㣩
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

LDL* CreatreLDListNode(DataType x)//��������ڵ�
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

void LDListDestroy(LDL* ph)//���������
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

void LDListPushBack(LDL* ph, DataType x)//β��
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

void LDListPopBack(LDL* ph)//βɾ
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

void LDListPushFront(LDL* ph, DataType x)//ͷ��
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

void LDListPopFront(LDL* ph)//ͷɾ
{
	/*assert(ph);
	assert(ph->next != ph);

	LDL* front = ph->next;

	front->next->prev = ph;
	ph->next = front->next;
	free(front);*/

	LDListErase(ph->next);
}

LDL* LDListFind(LDL* ph, DataType x)//���ҽڵ�
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

void LDListInsertBefore(LDL* pos, DataType x)//����ڵ�
{
	assert(pos);

	LDL* node = CreatreLDListNode(x);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}

void LDListErase(LDL* pos)//ɾ���ڵ�
{
	assert(pos);

	LDL* posprev = pos->prev;
	LDL* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}

void LDListPrint(LDL* ph)//��ӡ����
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