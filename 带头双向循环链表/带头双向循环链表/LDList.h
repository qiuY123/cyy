#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct LDList
{
	DataType val;
	struct LDList* prev;
	struct LDList* next;
}LDL;

LDL* LDListInit();//初始化循环链表（创建哨兵位节点）
LDL* CreatreLDListNode(DataType x);//创建链表节点
void LDListDestroy(LDL* ph);//链表的销毁
void LDListPushBack(LDL* ph, DataType x);//尾插
void LDListPopBack(LDL* ph);//尾删
void LDListPushFront(LDL* ph, DataType x);//头插
void LDListPopFront(LDL* ph);//头删
LDL* LDListFind(LDL* ph, DataType x);//查找节点
void LDListInsertBefore(LDL* pos, DataType x);//插入节点
void LDListErase(LDL* pos);//删除节点
void LDListPrint(LDL* ph);//打印链表