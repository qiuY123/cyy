#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int find_val(int arr[3][3], int row, int col, int find)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x < row && y >= 0)
//	{
//		if (arr[x][y] < find)
//		{
//			x++;
//		}
//		else if (arr[x][y] > find)
//		{
//			y--;
//		}
//		else
//		{
//			printf("找到了，下标是：%d %d\n", x, y);
//			return 1;
//		}
//	}
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int find = 0;
//	scanf("%d", &find);
//	int ret = find_val(arr, 3, 3, find);
//	if (ret!=1)
//	{
//		printf("没有该数字\n");
//	}
//	return 0;
//}

//char* left_rotate(char* arr,int n)
//{
//	char* p = arr;
//	int len = strlen(arr);
//	for (int i = 0; i < n; i++)
//	{
//		char temp = *p;
//		for (int j = 0; j < len - 1; j++)
//		{
//			*(p + j) = *(p + j + 1);
//		}
//		*(p + len - 1) = temp;
//	}
//	return arr;
//}
//
//int main()
//{
//	char arr[] = "abcd";
//	printf("旋转前：");
//	printf("%s\n", arr);
//	int n = 0;
//	scanf("%d", &n);
//	left_rotate(arr, n);
//	printf("旋转后：");
//	printf("%s\n", arr);
//
//	return 0;
//}

int is_rotate(char* arr1, char* arr2)
{
	char* ret = strstr(arr1, arr2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "bcdefa";
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	strncat(arr1, arr1, len1);
	int ret = is_rotate(arr1, arr2);
	if (len1 == len2)
	{
		if (ret == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}