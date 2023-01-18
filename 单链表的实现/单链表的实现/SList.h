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

SL* CreatreSListNode(DataType x);//����������ڵ�
void SListDestroy(SL** ph);//�����������
void SListPushBack(SL** ph,DataType x);//β��
void SListPopBack(SL** ph);//βɾ
void SListPushFront(SL** ph, DataType x);//ͷ��
void SListPopFront(SL** ph);//ͷɾ
SL* SListFind(SL* ph,DataType x);//���ҽڵ�
void SListInsertBefore(SL** ph,SL* pos,DataType x);//����ڵ�
void SListErase(SL* ph, SL* pos);//ɾ���ڵ�
void SListPrint(SL* ph);//��ӡ������