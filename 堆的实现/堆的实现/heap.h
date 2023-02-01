#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>

typedef int DataType;

typedef struct heap
{
	DataType* a;
	int size;
	int capacity;
}heap;

void CreatreHeap(heap* p);
void HeapInit(heap* p);
void HeapDestroy(heap* p);
void HeapPush(heap* p, DataType x);
void HeapPop(heap* p);
DataType HeapTop(heap* p);
void HeapPrint(heap* p);
int HeapEmpty(heap* p);
void HeapSort(DataType* a, int n);