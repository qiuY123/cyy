#define _CRT_SECURE_NO_WARNINGS 1 
//#include<stdio.h>
//int main()
//{
//	double a = 1.0;
//	int b = 0;
//	int flag = -1;
//	double sum = 0;
//	for (b = 1; b <= 100; b++)
//	{
//		double ret = a / b;
//		if (b % 2 == 0)
//		{
//			ret *= flag;
//		}
//		sum += ret;
//	}
//	printf("%f", sum);
//
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int count = 0;
//	for (int a = 1; a <= 100; a++)
//	{
//		if (a % 10 == 9)
//		{
//			count++;
//		}
//		else if (a / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void menu()
//{
//	printf("********************\n");
//	printf("****** 1.play ******\n");
//	printf("****** 0.exit ******\n");
//	printf("********************\n");
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int ret = rand() % 100 + 1;
//	int input = 0;
//	int x = 0;
//
//	menu();
//	
//	do
//	{
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			while (1)
//			{
//				printf("请选择一个数：");
//				scanf("%d", &x);
//				if (x == ret)
//				{
//					printf("恭喜你猜中了\n");
//					break;
//				}
//				else if (x > ret)
//				{
//					printf("很遗憾你猜大了，请重新选择：\n");
//				}
//				else
//				{
//					printf("很遗憾你猜小了，请重新选择：\n");
//				}
//			}
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择:");
//			break;
//		}
//		menu();
//	} while (input);
//
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
//int get_pos(int arr,int x,int sz)
//{
//	int pos = 0;
//	int left = 0;
//	int right = sz - 1;
//	int mid;
//	while (left<=right)
//	{
//		mid = (left + right) / 2;
//
//		if (x < arr[mid])
//		{
//			right = mid-1;
//		}
//		else if (x > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了\n");
//			break;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//	pos = mid;
//	return pos;
//}
int main()
{
	int x = 0;
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
	scanf("%d", &x);
	int left = 0;
	int right = sz - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (x < arr[mid])
		{
			right = mid - 1;
		}
		else if (x > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了,下标是：%d\n",mid);
			break;
		}
	}
	if (left > right)
	{
		printf("没找到\n");
	}
	return 0;
}