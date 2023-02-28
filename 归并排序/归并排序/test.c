#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void _MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, temp);
	_MergeSort(a, mid + 1, end, temp);

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	memcpy(a + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSortRe(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, temp);
}

void MergeSortNoRe(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int range = 1;
	while (range < n)
	{
		for (int i = 0; i < n; i += 2 * range)
		{
			int begin1 = i;
			int end1 = i + range - 1;
			int begin2 = i + range;
			int end2 = i + 2 * range - 1;
			if (end1 >= n)
			{
				break;
			}
			else if (begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[j++] = a[begin1++];
				}
				else
				{
					temp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				temp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				temp[j++] = a[begin2++];
			}
			//归并一部分拷贝一部分
			memcpy(a + i, temp + i, sizeof(int) * (end2 - i + 1));
		}
		range *= 2;
	}
	
	free(temp);
	temp = NULL;
}

//void MergeSortNoRe(int* a, int n)
//{
//	int* temp = (int*)malloc(sizeof(int) * n);
//	if (temp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	int range = 1;
//	while (range < n)
//	{
//		for (int i = 0; i < n; i += 2 * range)
//		{
//			int begin1 = i;
//			int end1 = i + range - 1;
//			int begin2 = i + range;
//			int end2 = i + 2 * range - 1;
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//				//不存在区间
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//			int j = i;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					temp[j++] = a[begin1++];
//				}
//				else
//				{
//					temp[j++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				temp[j++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				temp[j++] = a[begin2++];
//			}
//			
//		}
//		//归并完 整体拷贝
//		memcpy(a, temp, sizeof(int) * n);
//		range *= 2;
//	}
//
//	free(temp);
//	temp = NULL;
//}

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
	MergeSortRe(arr, size);
	printf("排序后：");
	print(arr, size);
	return 0;
}