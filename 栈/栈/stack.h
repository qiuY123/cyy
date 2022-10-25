#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Datetype;

typedef struct Stack
{
	Datetype* a;
	int top;
	int capacity;
}ST;

void StactInit(ST* p);
void StackDestory(ST* p);
void StackPush(ST* p, Datetype x);
void StackPop(ST* p);
Datetype StackTop(ST* p);
int StackSize(ST* p);
int StackEmpty(ST* p);
