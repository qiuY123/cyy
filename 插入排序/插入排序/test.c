#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp >= a[end])
			{
				break;
			}
			else
			{
				a[end + 1] = a[end];
				end--;
			}
		}
		a[end + 1] = temp;
	}
}

void print(int* a,int n)
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
	InsertSort(arr, size);
	printf("ÅÅÐòºó£º");
	print(arr,size);
	return 0;
}