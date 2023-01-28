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

LDL* LDListInit();//��ʼ��ѭ�����������ڱ�λ�ڵ㣩
LDL* CreatreLDListNode(DataType x);//��������ڵ�
void LDListDestroy(LDL* ph);//���������
void LDListPushBack(LDL* ph, DataType x);//β��
void LDListPopBack(LDL* ph);//βɾ
void LDListPushFront(LDL* ph, DataType x);//ͷ��
void LDListPopFront(LDL* ph);//ͷɾ
LDL* LDListFind(LDL* ph, DataType x);//���ҽڵ�
void LDListInsertBefore(LDL* pos, DataType x);//����ڵ�
void LDListErase(LDL* pos);//ɾ���ڵ�
void LDListPrint(LDL* ph);//��ӡ����