#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>

// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
//���µ����㷨
void AdjustDown(int* a, int n, int root);
// ������
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
// ��������ݹ�ʵ��
// ��������hoare�汾
int QuickSort1(int* a, int left, int right);
// ���������ڿӷ�
void QuickSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
void QuickSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
