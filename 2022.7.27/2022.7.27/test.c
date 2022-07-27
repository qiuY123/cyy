#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int count = 0;
//	int c = a ^ b;
//	int d = 1;
//	if (c == 0)
//	{
//		printf("%d", count);
//	}
//	else
//	{
//		while (c)
//		{
//			d = c & 1;
//			if (d)
//			{
//				count++;
//			}
//			c = c >> 1;
//		}
//		printf("%d", count);
//	}
//	return 0;
//}
//int main()
//{
//	int a;
//	int b = 0;
//	scanf("%d", &a);
//	for (int i = 31; i >= 1 ; i = i - 2)
//	{
//		b = (a >> i) & 1;
//		printf("%d ", b);
//	}
//	printf("\n");
//	for (int i = 32; i >= 2;i = i - 2)
//	{
//		b = (a >> i) & 1;
//		printf("%d ", b);
//	}
//	return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a >> i) & 1)
//		{
//			count++;
//		}
//	}
//	printf("%d ", count);
//	return 0;
//}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("交换前：");
	printf("%d %d", a, b);
	printf("\n");
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("交换后：");
	printf("%d %d", a, b);

	return 0;
}