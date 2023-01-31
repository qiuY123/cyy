#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct QueueNode
{
	DataType val;
	struct QueueNode* next;
}QN;

typedef struct Queue
{
	QN* head;
	QN* tail;
	size_t size;
}Queue;

void QueueInit(Queue* p);
void QueueDestory(Queue* p);
void QueuePush(Queue* p, DataType x);
void QueuePop(Queue* p);
DataType QueueFront(Queue* p);
DataType QueueBack(Queue* p);
int QueueEmpty(Queue* p);
int QueueSize(Queue* p);

