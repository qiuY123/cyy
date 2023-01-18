#define _CRT_SECURE_NO_WARNINGS 1 

#include"SList.h"

void test1()
{
	SL* p = NULL;

	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPrint(p);

	SListPopBack(&p);
	SListPopBack(&p);
	SListPrint(p);

	SListDestroy(&p);
}

void test2()
{
	SL* p = NULL;

	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	SListPushFront(&p, 4);
	SListPrint(p);

	SListPopFront(&p);
	SListPopFront(&p);
	SListPopFront(&p);
	SListPopFront(&p);
	SListPrint(p);

	SListDestroy(&p);
}

void test3()
{
	SL* p = NULL;

	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPrint(p);

	SL* pos1 = SListFind(p, 4);
	SListInsertBefore(&p, pos1, 0);
	SListPrint(p);

	SL* pos2 = SListFind(p, 1);
	SListErase(&p,pos2);
	SListPrint(p);

	SListDestroy(&p);
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}