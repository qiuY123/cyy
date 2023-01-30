#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* a;
	int capacity;
	int size;
}St;

void StackInit(St* p);
void StackDestory(St* p);
void StackPush(St* p, DataType x);
void StackPop(St* p);
DataType StackTop(St* p);
int StackSize(St* p);
int StackEmpty(St* p);