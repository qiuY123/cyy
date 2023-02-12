#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

void ShellSort(int* a, int n)
{
	int gap = 4;
	while (gap > 1)
	{
		gap = gap / 2;
		//gap=gap/3+1;���Գ��ʺϵ�������Ҫ��֤gap���Ϊ1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp >= a[end])
				{
					break;
				}
				else
				{
					a[end + gap] = a[end];
					end -= gap;
				}
			}
			a[end + gap] = temp;
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
	printf("����ǰ��");
	print(arr, size);
	ShellSort(arr, size);
	printf("�����");
	print(arr, size);
	return 0;
}