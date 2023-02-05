#define _CRT_SECURE_NO_WARNINGS 1 

#include"tree.h"

void test1()
{
	BT* n1 = CreatreTreeNode(1);
	BT* n2 = CreatreTreeNode(2);
	BT* n3 = CreatreTreeNode(3);
	BT* n4 = CreatreTreeNode(4);
	BT* n5 = CreatreTreeNode(5);
	BT* n6 = CreatreTreeNode(6);
	BT* n7 = CreatreTreeNode(7);

	n1->leftchild = n2;
	n1->rightchild = n3;
	n2->leftchild = n4;
	n2->rightchild = n7;
	n3->leftchild = n5;
	n3->rightchild = n6;

	Preorder(n1);
	printf("\n");
	Inorder(n1);
	printf("\n");
	Postorder(n1);
	printf("\n");
	Levelorder(n1);
	printf("\n");

	printf("TreeNodeSize:%d\n", TreeNodeSize(n1));
	printf("TreeHigh:%d\n", TreeHigh(n1));
	printf("TreeLeafSize:%d\n", TreeLeafSize(n1));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1,2));
	printf("IsTreeComplete:%d\n", TreeComplete(n1));
}

int main()
{
	test1();
	return 0;
}