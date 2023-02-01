#define _CRT_SECURE_NO_WARNINGS 1 

#include"heap.h"

void swap(DataType* x, DataType* y)
{
	DataType temp = *x;
	*x = *y;
	*y = temp;
}

void AdjustUp(DataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(DataType* a, int n, int parent)
{
	int leftchild = parent * 2 + 1;
	while (leftchild < n)
	{
		if (leftchild + 1 < n && a[leftchild] > a[leftchild + 1])
		{
			leftchild++;
		}
		if (a[parent] > a[leftchild])
		{
			swap(&a[parent], &a[leftchild]);
			parent = leftchild;
			leftchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(heap* p, DataType x)
{
	assert(p);
	if (p->size == p->capacity)
	{
		int newcapacity = p->capacity == 0 ? 4 : 2 * p->capacity;
		DataType* temp = (DataType*)realloc(p->a, sizeof(DataType) * newcapacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		p->a = temp;
		p->capacity = newcapacity;
	}
	p->a[p->size] = x;
	p->size++;
	AdjustUp(p->a, p->size - 1);
}

void HeapInit(heap* p)
{
	assert(p);
	p->a = NULL;
	p->capacity = p->size = 0;
}

void CreatreHeap1(heap* p,DataType* a)//向上建堆
{
	assert(p);

	HeapInit(p);
	for (int i = 0; i < p->size; i++)
	{
		HeapPush(p, a[i]);
	}
}

void CreatreHeap2(heap* p,DataType* a,int n)//向下建堆
{
	assert(p);

	p->a = (DataType*)malloc( sizeof(DataType) * n);
	if (p->a == NULL)
	{
		printf("mallloc fail\n");
		exit(-1);
	}
	memcpy(p->a, a, sizeof(DataType) * n);
	p->capacity = p->size = n;
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(p->a, n, i);
	}
}

void HeapDestroy(heap* p)
{
	assert(p);
	free(p->a);
	p->capacity = p->size = 0;
}

void HeapPop(heap* p) 
{
	assert(p);
	assert(p->size > 0);

	swap(&p->a[0], &p->a[p->size - 1]);
	p->size--;
	AdjustDown(p->a, p->size, 0);
}

DataType HeapTop(heap* p)
{
	assert(p);
	return p->a[0];
}

void HeapPrint(heap* p)
{
	assert(p);
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}

int HeapEmpty(heap* p)
{
	assert(p);
	if (p->size)
	{
		return 1;
	}
	return 0;
}

void HeapSort(DataType* a, int n)
{
	//for (int i = 1; i < n; i++)//向上调整建堆
	//{
	//	AdjustUp(a, i);
	//}
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//向下调整建堆
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}