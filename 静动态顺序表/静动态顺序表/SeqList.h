#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Datatype;

//静态
//#define size 100
//
//typedef struct SeqList
//{
//	Datatype a[size];
//	int count;
//}SL;

//动态
typedef struct SeqList
{
	Datatype* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* p);//顺序表初始化
void SeqListDestroy(SL* p);//顺序表的销毁
void SeqListCheckCapacity(SL* p);//检查容量
void SeqListPushBack(SL* p, Datatype x);//尾插
void SeqListPopBack(SL* p);//尾删
void SeqListPushFront(SL* p, Datatype x);//头插
void SeqListPopFront(SL* p);//头删
void SeqListInsert(SL* p, int pos, Datatype x);//选择位置插入
void SeqListErase(SL* p, int pos);//选择位置删除
//int SeqListFind(SL* p, Datatype x);//寻找数返回下标
int SeqListFind(SL* p, Datatype x, int begin);//寻找数返回下标
void SeqListPrint(SL* p);//打印