#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>

//char* my_strncat(char* e1, const char* e2, size_t sz)
//{
//	char* start = e1;
//	while(*e1)
//	{
//		e1++;
//	}
//	while (sz--)
//	{
//		*e1++ = *e2++;
//	}
//	return start;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[10] = "world";
//	printf("%s\n", arr1);
//	my_strncat(arr1, arr2, 4);
//	printf("%s\n", arr1);
//	return 0;
//}
char* my_strncpy(char* e1, const char* e2, size_t sz)
{
	char* start = e1;
	if (sz)
	{
		while (sz && (*e1++ = *e2++))
		{
			sz--;
		}
	}
	return start;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[10] = "world";
	printf("%s\n", arr1);
	my_strncpy(arr1, arr2, 7);
	printf("%s\n", arr1);

	return 0;
}
//int* Find_single(int* arr,int sz)
//{
//	int k = 0;
//	int* p1 = (int*)malloc(sizeof(int) * 2);
//	for (int i = 0; i < sz; i++)
//	{
//		int count = 0;
//		for (int j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//		if (count == 1)
//		{
//			p1[k++] = arr[i];
//		}
//	}
//	return p1;
//}
//int main()
//{
//	int arr[10] = { 0,1,2,2,3,4,3,5,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p2 = Find_single(arr, sz);
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%d ", *(p2 + i));
//	}
//	return 0;
//}
//int is_valid = 0;
//int my_atoi(const char* p)
//{
//	int invalid = 0;
//	int valid = 1;
//	int flag = 1;
//	if (NULL == p)
//	{
//		return invalid;
//	}
//	if ('\0' == *p)
//	{
//		return invalid;
//	}
//	while (isspace(*p))
//	{
//		p++;
//	}
//	if ('-' == p)
//	{
//		flag = -1;
//		p++;
//	}
//	else if('+' == p)
//	{
//		flag = 1;
//		p++;
//	}
//	long long n = 0;
//	while (isdigit(*p))
//	{
//		n = n * 10 + flag * (*p - '0');
//		if (n > INT_MAX || n < INT_MIN)
//		{
//			return invalid;
//		}
//		p++;
//	}
//	if ('\0' == *p)
//	{
//		is_valid = valid;
//		return (int)n;
//	}
//	else
//	{
//		return (int)n;
//	}
//}
//
//int main()
//{
//	const char* p = "  123456";
//	int ret = my_atoi(p);
//	
//	printf("%d\n", ret);
//	return 0;
//}