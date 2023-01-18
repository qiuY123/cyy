#define _CRT_SECURE_NO_WARNINGS 1 

#include"SList.h"

SL* CreatreSListNode(DataType x)//����������ڵ�
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SListDestroy(SL** ph)//�����������
{
	SL* cur = *ph;
	while (cur)
	{
		SL* next = cur->next;
		free(cur);
		cur = next;
	}
	*ph = NULL;
}

void SListPushBack(SL** ph, DataType x)//β��
{

	SL* newnode = CreatreSListNode(x);
	if (*ph == NULL)
	{
		*ph = newnode;
	}
	else
	{
		SL* tail = *ph;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SL** ph)//βɾ
{
	assert(*ph);
	if ((*ph)->next == NULL)
	{
		free(*ph);
		*ph = NULL;
	}
	else
	{
		SL* prev = NULL;
		SL* tail = *ph;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
	
}

void SListPushFront(SL** ph, DataType x)//ͷ��
{
	SL* newnode = CreatreSListNode(x);
	newnode->next = *ph;
	*ph = newnode;
}

void SListPopFront(SL** ph)//ͷɾ
{
	assert(*ph);

	SL* next = (*ph)->next;
	free(*ph);
	*ph = next;
}

SL* SListFind(SL* ph, DataType x)//���ҽڵ�
{
	SL* cur = ph;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertBefore(SL** ph, SL* pos, DataType x)//����ڵ�
{
	assert(pos);

	if (*ph == pos)
	{
		SListPushFront(ph, x);
	}
	else
	{
		SL* prev = *ph;
		SL* newnode = CreatreSListNode(x);
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SL** ph, SL* pos)//ɾ���ڵ�
{
	assert(*ph);
	assert(pos);

	if (*ph == pos)
	{
		SListPopFront(ph);
	}
	else
	{
		SL* prev = *ph;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListPrint(SL* ph)//��ӡ������
{
	SL* cur = ph;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}