#define _CRT_SECURE_NO_WARNINGS 1 

#include"heap.h"

// 堆的构建
void HeapCreate(Heap* hp)
{
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->capacity = hp->size = 0;
}
//交換兩個數的值
void swap(HPDataType* x, HPDataType* y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}
//向上調整算法
void Adjustup(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//向下調整算法
void Adjustdown(HPDataType* a, int n,int parent)
{
	int leftchild = parent * 2 + 1;
	while (leftchild < n)
	{
		if (leftchild + 1 < n && a[leftchild] < a[leftchild + 1])
		{
			leftchild++;
		}
		if (a[leftchild] > a[parent])
		{
			swap(&a[leftchild], &a[parent]);
			parent = leftchild;
			leftchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 打印堆
void Heapprint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		int newcapacity = hp->capacity == 0 ? 5 : 2 * hp->capacity;
		HPDataType* temp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = temp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;
	Adjustup(hp->a, hp->size - 1);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	Adjustdown(hp->a, hp->size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp) 
{
	assert(hp);
	if (hp->size)
	{
		return 1;
	}
	return 0;
}