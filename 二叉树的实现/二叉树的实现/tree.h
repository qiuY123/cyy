#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct BinaryTree
{
	DataType val;
	struct BinaryTree* leftchild;
	struct BinaryTree* rightchild;
}BT;

void Preorder(BT* root);
void Inorder(BT* root);
void Postorder(BT* root);
void Levelorder(BT* root);
BT* CreatreTreeNode(DataType x);
int TreeNodeSize(BT* root);
int TreeHigh(BT* root);
int TreeLeafSize(BT* root);
int TreeKLevelSize(BT* root, int k);
int TreeComplete(BT* root);
void TreeDestroy(BT* root);
int MaxNode(BT* root);

