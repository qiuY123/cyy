#define _CRT_SECURE_NO_WARNINGS 1 

#include"sort.h"

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void testInsertSort(int* arr, int size)
{
	printf("��������");
	InsertSort(arr,size);
	print(arr, size);
}

void testShellSort(int* arr, int size)
{
	printf("ϣ������");
	ShellSort(arr, size);
	print(arr, size);
}

void testSelectSort(int* arr, int size)
{
	printf("ѡ������");
	SelectSort(arr, size);
	print(arr, size);
}

void testHeapSort(int* arr, int size)
{
	printf("������");
	HeapSort(arr, size);
	print(arr, size);
}

void testBubbleSort(int* arr, int size)
{
	printf("ð������");
	BubbleSort(arr, size);
	print(arr, size);
}

void testQuickSort(int* arr, int size)
{
	printf("��������");
	QuickSort(arr, 0, size - 1);
	print(arr, size);
}

int main()
{
	int arr[] = { 0,5,7,4,1,9,6,8,3,2 };
	int count = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��");
	print(arr, count);
	testInsertSort(arr, count);
	testShellSort(arr, count);
	testSelectSort(arr, count);
	testHeapSort(arr, count);
	testBubbleSort(arr, count); 
	testQuickSort(arr, count);
	return 0;
}