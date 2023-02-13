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
		//��Ϊ�Ѿ�����λ���ˣ�����Ҫ�Ժ�һ�����������жϡ�����beginλ�õ�����󣬵�������min���н������ˣ�������������minλ����
		if (begin == max)
		{
			max = min;//max���¸�ֵmin
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
	printf("����ǰ��");
	print(arr, size);
	SelectSort(arr, size);
	printf("�����");
	print(arr, size);
	return 0;
}