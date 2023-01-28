#define _CRT_SECURE_NO_WARNINGS 1 

#include"LDList.h"

void test1()
{
	LDL* ptr = LDListInit();
	LDListPushBack(ptr, 1);
	LDListPushBack(ptr, 2);
	LDListPushBack(ptr, 3);
	LDListPushBack(ptr, 4);
	LDListPrint(ptr);
	
	LDListPopBack(ptr);
	LDListPopBack(ptr);
	//LDListPopBack(ptr);
	//LDListPopBack(ptr);
	LDListPrint(ptr);

	LDListDestroy(ptr);
}

void test2()
{
	LDL* ptr = LDListInit();
	LDListPushFront(ptr, 1);
	LDListPushFront(ptr, 2);
	LDListPushFront(ptr, 3);
	LDListPushFront(ptr, 4);
	LDListPrint(ptr);

	LDListPopFront(ptr);
	LDListPopFront(ptr);
	/*LDListPopFront(ptr);
	LDListPopFront(ptr);*/
	LDListPrint(ptr); 

	LDListDestroy(ptr);
}

void test3()
{
	LDL* ptr = LDListInit();
	LDListPushBack(ptr, 1);
	LDListPushBack(ptr, 2);
	LDListPushBack(ptr, 3);
	LDListPushBack(ptr, 4);
	LDListPushFront(ptr, 1);
	LDListPushFront(ptr, 2);
	LDListPushFront(ptr, 3);
	LDListPushFront(ptr, 4);
	LDListPrint(ptr);

	LDL* pos1 = LDListFind(ptr, 3);
	LDListInsertBefore(pos1, 2);
	LDListPrint(ptr);

	LDL* pos2 = LDListFind(ptr, 2);
	LDListErase(pos2);
	LDListPrint(ptr);

	LDListDestroy(ptr);
}

int main()
{
	/*test1();
	test2();*/
	test3();

	return 0;
}