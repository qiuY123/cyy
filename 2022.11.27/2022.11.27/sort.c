#define _CRT_SECURE_NO_WARNINGS 1 

#include"sort.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (tem < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tem;
	}
}
// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tem = a[end + gap];
			while (end >= 0)
			{
				if (tem < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tem;
		}
	}
}
// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(&a[mini], &a[begin]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}
//向下调整算法
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] < a[child] && child + 1 < n)
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			int tem = a[parent];
			a[parent] = a[child];
			a[child] = tem;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
// 堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		int tem = a[end];
		a[end] = a[0];
		a[0] = tem;
		AdjustDown(a, end, 0);
		--end;
	}
}
// 冒泡排序
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end)
	{
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				int tem = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tem;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}
// 快速排序递归实现
// 快速排序hoare版本
int QuickSort1(int* a, int begin, int end)
{
	int key = a[begin];
	while (begin < end)
	{
		while (key <= a[end] && begin < end)
		{
			--end;
		}
		a[begin] = a[end];
		while (key >= a[begin] && begin < end)
		{
			++begin;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	int meeti = begin;
	return meeti;
}
// 快速排序挖坑法
void QuickSort2(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin, right = end;
	int key = a[begin];
	while (begin < end)
	{
		//找小
		while (a[end] >= key && begin < end)
		{
			--end;
		}
		//小的放到左边的坑里
		a[begin] = a[end];
		//找大
		while (a[begin] <= key && begin < end)
		{
			++begin;
		}
		//大的放到右边的坑里
		a[end] = a[begin];
	}
	a[begin] = key;
	int keyi = begin;
	//[left,keyi-1]keyi[keyi+1,right]
	QuickSort2(a, left, keyi - 1);
	QuickSort2(a, keyi + 1, right);
}
// 快速排序前后指针法
void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int cur = begin, prev = begin - 1;
	int keyi = end;
	while (cur != keyi)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	swap(&a[++prev], &a[keyi]);
	keyi = prev;
	//[begin,keyi -1]keyi[keyi+1,end]
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}
void QuickSort(int* a, int begin, int end)
{
	//只有一个数或区间不存在
	if (begin >= end)
		return;
	int left = begin;
	int right = end;
	//选左边为key
	int keyi = begin;
	while (begin < end)
	{
		//右边选小   等号防止和key值相等    防止顺序begin和end越界
		while (a[end] >= a[keyi] && begin < end)
		{
			--end;
		}
		//左边选大
		while (a[begin] <= a[keyi] && begin < end)
		{
			++begin;
		}
		//小的换到右边，大的换到左边
		swap(&a[begin], &a[end]);
	}
	swap(&a[keyi], &a[end]);
	keyi = end;
	//[left,keyi-1]keyi[keyi+1,right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{

}