#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

void swap(int* x,int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swap(&a[begin], &a[min]);
		//因为已经交换位置了，所以要对后一个交换进行判断。比如begin位置的数最大，但是它与min进行交换过了，所以最大的数在min位置上
		if (begin == max)
		{
			max = min;//max重新赋值min
		}
		swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 5,84,32,44,58,64,23,78,92,13 };
	int size = sizeof(arr) / sizeof(int);
	printf("排序前：");
	print(arr, size);
	SelectSort(arr, size);
	printf("排序后：");
	print(arr, size);
	return 0;
}