#define _CRT_SECURE_NO_WARNINGS 1 

#include"heap.h"

void test()
{
	int arr[] = { 11,15,24,61,9,32,51,55,63 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	HeapCreate(&hp);
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	Heapprint(&hp);
	while(HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
	Heapprint(&hp);
	HeapDestory(&hp);
}

int main()
{
	test();


	return 0;
}