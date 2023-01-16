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

	//这里有个缺点：只能找到第一个要查找的数返回其下标，然后调用SeqListErase函数删除，后面要查找的数无法删除
	/*int pos = SeqListFind(&ptr, 1);
	SeqListErase(&ptr, pos);
	SeqListPrint(&ptr);*/

	//修改
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