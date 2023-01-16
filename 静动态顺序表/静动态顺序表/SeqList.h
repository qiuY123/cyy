#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Datatype;

//��̬
//#define size 100
//
//typedef struct SeqList
//{
//	Datatype a[size];
//	int count;
//}SL;

//��̬
typedef struct SeqList
{
	Datatype* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* p);//˳����ʼ��
void SeqListDestroy(SL* p);//˳��������
void SeqListCheckCapacity(SL* p);//�������
void SeqListPushBack(SL* p, Datatype x);//β��
void SeqListPopBack(SL* p);//βɾ
void SeqListPushFront(SL* p, Datatype x);//ͷ��
void SeqListPopFront(SL* p);//ͷɾ
void SeqListInsert(SL* p, int pos, Datatype x);//ѡ��λ�ò���
void SeqListErase(SL* p, int pos);//ѡ��λ��ɾ��
//int SeqListFind(SL* p, Datatype x);//Ѱ���������±�
int SeqListFind(SL* p, Datatype x, int begin);//Ѱ���������±�
void SeqListPrint(SL* p);//��ӡ