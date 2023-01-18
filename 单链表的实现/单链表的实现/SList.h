#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct SList
{
	DataType val;
	struct SList* next;
}SL;

SL* CreatreSListNode(DataType x);//创建单链表节点
void SListDestroy(SL** ph);//单链表的销毁
void SListPushBack(SL** ph,DataType x);//尾插
void SListPopBack(SL** ph);//尾删
void SListPushFront(SL** ph, DataType x);//头插
void SListPopFront(SL** ph);//头删
SL* SListFind(SL* ph,DataType x);//查找节点
void SListInsertBefore(SL** ph,SL* pos,DataType x);//插入节点
void SListErase(SL* ph, SL* pos);//删除节点
void SListPrint(SL* ph);//打印单链表