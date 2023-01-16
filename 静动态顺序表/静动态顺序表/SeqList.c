#define _CRT_SECURE_NO_WARNINGS 1 

#include"SeqList.h"

void SeqListInit(SL* p)//˳����ʼ��
{
	//��̬
	//assert(p);
	//p->count = 0;

	//��̬
	assert(p);
	p->a = NULL;
	p->capacity = p->size = 0;
}

void SeqListDestroy(SL* p)//˳��������
{
	//��̬
	//assert(p);
	//p->count = 0;

	//��̬
	assert(p);
	if (p->a) 
	{
		free(p->a);
		p->capacity = 0;
		p->size = 0;
	}
}

void SeqListCheckCapacity(SL* p)
{
	assert(p);
	if (p->capacity == p->size)
	{
		int newcapacity = p->capacity == 0 ? 4 : 2 * p->capacity;
		Datatype* temp = (Datatype*)realloc(p->a, newcapacity * sizeof(Datatype));
		if (temp)
		{
			p->a = temp;
			p->capacity = newcapacity;
		}
		else
		{
			printf("relloc fail\n");
			exit(-1);
		}
	}
}

void SeqListPushBack(SL* p, Datatype x)//β��
{
	//��̬
	///*assert(p);
	//if (p->count == size)
	//{
	//	printf("˳����������޷����\n");
	//	return;
	//}
	//p->a[p->count] = x;
	//p->count++;*/

	//SeqListInsert(p, p->count, x);

	//��̬
	/*SeqListCheckCapacity(p);
	p->a[p->size] = x;
	p->size++;*/

	SeqListInsert(p, p->size, x);
}

void SeqListPopBack(SL* p)//βɾ
{
	//��̬
	///*assert(p);
	//assert(p->count > 0);
	//p->count--;*/

	//SeqListErase(p, p->count - 1);

	//��̬
	/*assert(p);
	assert(p->size > 0);

	p->size--;*/

	SeqListErase(p, p->size - 1);
}
void SeqListPushFront(SL* p, Datatype x)//ͷ��
{
	//��̬
	///*assert(p);
	//if (p->count == size)
	//{
	//	printf("˳����������޷����\n");
	//	return;
	//}
	//for (int i = p->count; i > 0; i--)
	//{
	//	p->a[i] = p->a[i - 1];
	//}
	//p->a[0] = x;
	//p->count++;*/

	//SeqListInsert(p, 0, x);

	//��̬
	/*SeqListCheckCapacity(p);
	for (int i = p->size; i > 0; i--)
	{
		p->a[i] = p->a[i - 1];
	}
	p->a[0] = x;
	p->size++;*/

	SeqListInsert(p, 0, x);
}

void SeqListPopFront(SL* p)//ͷɾ
{
	//��̬
	///*assert(p);
	//assert(p->count > 0);
	//for (int i = 0; i < p->count; i++)
	//{
	//	p->a[i] = p->a[i + 1];
	//}
	//p->count--;*/

	//SeqListErase(p, 0);

	//��̬
	/*assert(p);
	assert(p->size > 0);

	for (int i = 0; i < p->size; i++)
	{
		p->a[i] = p->a[i + 1];
	}
	p->size--;*/

	SeqListErase(p, 0);
}

void SeqListInsert(SL* p, int pos, Datatype x)//ѡ��λ�ò���
{
	//��̬
	//assert(p);
	//assert(pos >= 0);
	//assert(pos <= p->count);

	//if (p->count == size)
	//{
	//	printf("˳����������޷����\n");
	//	return;
	//}
	//for (int i = p->count; i > pos; i--)
	//{
	//	p->a[i] = p->a[i - 1];
	//}
	//p->a[pos] = x;
	//p->count++;

	//��̬
	assert(p);
	assert(pos >= 0);
	assert(pos <= p->size);

	SeqListCheckCapacity(p);
	for (int i = p->size; i > pos; i--)
	{
		p->a[i] = p->a[i - 1];
	}
	p->a[pos] = x;
	p->size++;
}

void SeqListErase(SL* p, int pos)//ѡ��λ��ɾ��
{
	//��̬
	//assert(p);
	//assert(p->count > 0);
	//assert(pos >= 0);
	//assert(pos < p->count);

	//for (int i = pos; i < p->count; i++)
	//{
	//	p->a[i] = p->a[i + 1];
	//}
	//p->count--;

	//��̬
	assert(p);
	assert(p->size > 0);
	assert(pos >= 0);
	assert(pos < p->size);

	for (int i = pos; i < p->size; i++)
	{
		p->a[i] = p->a[i + 1];
	}
	p->size--;
}

//int SeqListFind(SL* p, Datatype x)//Ѱ���������±�
//{
//	assert(p);
//	for (int i = 0; i < p->count; i++)
//	{
//		if (p->a[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;//��˳�����û�и�ֵ�򷵻�-1��
//}
int SeqListFind(SL* p, Datatype x,int begin)
{
	//��̬
	//assert(p);
	//for (int i = begin; i < p->count; i++)
	//{
	//	if (p->a[i] == x)
	//	{
	//		return i;
	//	}
	//}
	//return -1;//��˳�����û�и�ֵ�򷵻�-1��

	//��̬
	assert(p);
	for (int i = begin; i < p->size; i++)
	{
		if (p->a[i] == x)
		{
			return i;
		}
	}
	return -1;//��˳�����û�и�ֵ�򷵻�-1��
}

void SeqListPrint(SL* p)//��ӡ
{
	//for (int i = 0; i < p->count; i++)
	//{
	//	printf("%d ", p->a[i]);
	//}
	//printf("\n");

	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}