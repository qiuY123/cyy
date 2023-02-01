#define _CRT_SECURE_NO_WARNINGS 1 

#include"heap.h"

void test1()
{
	DataType arr[] = { 11,52,48,63,2,6,49,71,108,36 };
	int size = sizeof(arr) / sizeof(DataType);
	heap hp;
	HeapInit(&hp);
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);
	while (HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapDestroy(&hp);
}

void test2()
{
	DataType arr[] = { 11,52,48,63,2,6,49,71,108,36 };
	int size = sizeof(arr) / sizeof(DataType);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TopK()
{
	DataType arr[10000];
	int size = sizeof(arr) / sizeof(DataType);
	int k = 10;
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	DataType maxarr[10];
	for (int i = 0; i < k; i++)
	{
		maxarr[i] = arr[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(maxarr, k, i);
	}
	for (int i = 0; i < size - k; i++)
	{
		if (arr[k + i] > maxarr[0])
		{
			maxarr[0] = arr[k + i];
			AdjustDown(maxarr, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", maxarr[i]);
	}
	printf("\n");
}

int main()
{
	//test1();
	//test2();
	TopK();
	return 0;
}