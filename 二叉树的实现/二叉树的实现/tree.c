#define _CRT_SECURE_NO_WARNINGS 1 

#include"tree.h"
#include"Queue.h"

void Preorder(BT* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d ", root->val);
	Preorder(root->leftchild);
	Preorder(root->rightchild);
}

void Inorder(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	
	Preorder(root->leftchild);
	printf("%d ", root->val);
	Preorder(root->rightchild);
}

void Postorder(BT* root)
{
	if (root == NULL)
	{
		return;
	}

	Preorder(root->leftchild);
	Preorder(root->rightchild);
	printf("%d ", root->val);
}

void Levelorder(BT* root)
{
	Queue q;
	QueueInit(&q);
	int QueueLevel = 0;
	if (root)
	{
		QueuePush(&q, root);
		QueueLevel = 1;
	}
	
	while (QueueEmpty(&q))
	{
		while (QueueLevel--)
		{
			struct BinaryTree* cur = QueueFront(&q);
			printf("%d ", cur->val);
			QueuePop(&q);
			if (cur->leftchild)
			{
				QueuePush(&q, cur->leftchild);
			}
			if (cur->rightchild)
			{
				QueuePush(&q, cur->rightchild);
			}
		}
		QueueLevel = QueueSize(&q);
		printf("\n");
	}
	
	QueueDestory(&q);
}

int TreeComplete(BT* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q))
	{
		struct BinaryTree* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, cur->leftchild);
			QueuePush(&q, cur->rightchild);
		}
	}
	while (QueueEmpty(&q))
	{
		struct BinaryTree* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur)
		{
			QueueDestory(&q);
			return 0;
		}
	}
	QueueDestory(&q);
	return 1;
}

BT* CreatreTreeNode(DataType x)
{
	BT* node = (BT*)malloc(sizeof(BT));
	if (node == NULL)
	{
		printf("malloc fail\n");
		return;
	}
	node->val = x;
	node->leftchild = NULL;
	node->rightchild = NULL;
	return node;
}

int TreeNodeSize(BT* root)
{
	return root == NULL ? 0 : TreeNodeSize(root->leftchild) + TreeNodeSize(root->rightchild) + 1;
}

int TreeHigh(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftTreeHigh = TreeHigh(root->leftchild);
	int rightTreeHigh = TreeHigh(root->rightchild);

	return leftTreeHigh > rightTreeHigh ? leftTreeHigh + 1 : rightTreeHigh + 1;
}

int TreeLeafSize(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->leftchild == NULL && root->rightchild == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->leftchild) + TreeLeafSize(root->rightchild);
}

int TreeKLevelSize(BT* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLevelSize(root->leftchild, k - 1) + TreeKLevelSize(root->rightchild, k - 1);
}

void TreeDestroy(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestroy(root->leftchild);
	TreeDestroy(root->rightchild);
	free(root);
}

int MaxNode(BT* root)
{

}