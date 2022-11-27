#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>

// 插入排序
void InsertSort(int* a, int n);
// 希尔排序
void ShellSort(int* a, int n);
// 选择排序
void SelectSort(int* a, int n);
//向下调整算法
void AdjustDown(int* a, int n, int root);
// 堆排序
void HeapSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n);
// 快速排序递归实现
// 快速排序hoare版本
int QuickSort1(int* a, int left, int right);
// 快速排序挖坑法
void QuickSort2(int* a, int left, int right);
// 快速排序前后指针法
void QuickSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
