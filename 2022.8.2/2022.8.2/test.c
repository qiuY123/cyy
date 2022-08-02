#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

//void Print(int* arr,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, len);
//	return 0;
//}
//
//int main()
//{
//    char arr[10000];
//    gets(arr);
//    int len = strlen(arr);
//    for (int i = len - 1; i >= 0; i--)
//    {
//        printf("%c", arr[i]);
//    }
//    return 0;
//}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 2 * n; i++)
		{
			if (i < n - j - 1)
			{
				printf(" ");
			}
			else if (i > n + j - 1)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	for (int j = n - 1; j > 0; j--)
	{
		for (int i = 0; i < 2 * n - 2 ; i++)
		{
			if (i < n - j )
			{
				printf(" ");
			}
			else if (i > n + j - 2)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}