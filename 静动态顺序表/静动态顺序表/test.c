#define _CRT_SECURE_NO_WARNINGS 1 

#include"SeqList.h"

void test1()
{
	SL ptr;
	SeqListInit(&ptr);

	SeqListPushBack(&ptr, 1);
	SeqListPushBack(&ptr, 2);
	SeqListPushBack(&ptr, 3);
	SeqListPushBack(&ptr, 4);
	SeqListPrint(&ptr);

	SeqListPopBack(&ptr);
	SeqListPopBack(&ptr);
	SeqListPopBack(&ptr);
	SeqListPrint(&ptr);

	SeqListDestroy(&ptr);
}

void test2()
{
	SL ptr;
	SeqListInit(&ptr);

	SeqListPushFront(&ptr, 1);
	SeqListPushFront(&ptr, 2);
	SeqListPushFront(&ptr, 3);
	SeqListPushFront(&ptr, 4);
	SeqListPrint(&ptr);

	SeqListPopFront(&ptr);
	SeqListPopFront(&ptr);
	SeqListPopFront(&ptr);
	SeqListPrint(&ptr);

	SeqListDestroy(&ptr);
}

void test3()
{
	SL ptr;
	SeqListInit(&ptr);

	SeqListPushFront(&ptr, 1);
	SeqListPushFront(&ptr, 2);
	SeqListPushFront(&ptr, 3);
	SeqListPushFront(&ptr, 4);
	SeqListPrint(&ptr);

	SeqListPushBack(&ptr, 4);
	SeqListPushBack(&ptr, 3);
	SeqListPushBack(&ptr, 2);
	SeqListPushBack(&ptr, 1);
	SeqListPrint(&ptr);

	SeqListInsert(&ptr, 8, 5);
	SeqListInsert(&ptr, 1, 5);
	SeqListPrint(&ptr);

	SeqListErase(&ptr, 0);
	SeqListPrint(&ptr);

	//�����и�ȱ�㣺ֻ���ҵ���һ��Ҫ���ҵ����������±꣬Ȼ�����SeqListErase����ɾ��������Ҫ���ҵ����޷�ɾ��
	/*int pos = SeqListFind(&ptr, 1);
	SeqListErase(&ptr, pos);
	SeqListPrint(&ptr);*/

	//�޸�
	int pos = SeqListFind(&ptr, 1, 0);
	while (pos != -1)
	{
		SeqListErase(&ptr, pos);
		pos = SeqListFind(&ptr, 1, pos);
	}
	SeqListPrint(&ptr);

	SeqListDestroy(&ptr);
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}