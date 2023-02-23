#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap(&a[j - 1], &a[j]);
			}
		}
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
	printf("ÅÅÐòÇ°£º");
	print(arr, size);
	BubbleSort(arr, size);
	printf("ÅÅÐòºó£º");
	print(arr, size);
	return 0;
}