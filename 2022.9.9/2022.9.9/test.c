#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

unsigned int my_strlen(const char* str)
{
	unsigned int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
char* my_strcpy(char* str,const char* arr)
{
	assert(arr != NULL);
	while (*str++ = *arr++)
	{

	}
	return str;
}
int my_strcmp(const char* str, const char* arr)
{
	while (*str == *arr)
	{
		str++;
		arr++;
	}
	if (*str > *arr)
	{
		return 1;
	}
	else if (*str < *arr)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
char* my_strcat(char* str, const char* arr)
{
	assert(arr);
	while (*str != '\0')
	{
		str++;
	}
	while (*arr)
	{
		*str = *arr;
		arr++;
		str++;
	}
	return str;
}
char* my_strstr(const char* str, const char* arr)
{
	assert(str && arr);
	const char* s1 = str;
	const char* s2 = arr;
	char* p = str;
	if (*arr == '\0')
	{
		return (char*)str;
	}
	while (*p)
	{
		s1 = p;
		s2 = arr;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	char arr[20] = "abcdefg";
	char arr1[] = "abc";
	char* ret = my_strstr(arr, arr1);
	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了，%s", ret);
	}
	/*my_strcat(arr, arr1);
	printf("%s", arr);*/
	//int x = my_strcmp(arr, arr1);
	//if (x == 0)
	//{
	//	printf("arr=arr1");
	//}
	//else if (x > 1)
	//{
	//	printf("arr>arr1");
	//}
	//else
	//{
	//	printf("arr<arr1");
	//}
	/*int x = my_strlen(arr);
	printf("%u", x);*/
	//my_strcpy(arr1, arr);
	//printf("%s", arr1);
	return 0;
}