#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>

//void print_table(int x)
//{
//	for (int i = 1; i <= x; i++)
//	{
//		for (int j = x; j >= i; j--)
//		{
//			printf("%d*%d=%-4d", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int is_year(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year / 400 == 0))
//	{
//		return 0;
//	}
//	else
//	{
//		return -1;
//	}
//}
int is_prime(int value)
{
	for (int i = 2; i < value; i++)
	{
		if (value % i == 0)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	//int x = 0;
	//scanf("%d", &x);
	//print_table(x);
	/*int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("%d %d", a, b);*/
	//int year = 0;
	//scanf("%d", &year);
	//int t = is_year(year);
	//if (t == 0)
	//{
	//	printf("%d是闰年", year);
	//}
	//else 
	//{
	//	printf("%d不是闰年", year);
	//}
	int value = 0;
	scanf("%d", &value);
	int x = is_prime(value);
	if (x == 0)
	{
		printf("%d是素数",value);
	}
	else
	{
		printf("%d不是素数", value);
	}
	return 0;
}