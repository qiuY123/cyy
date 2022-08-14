#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>

//void print(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//}
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int arr[10] = { 5,8,3,4,1,6,10,7,2,9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	printf("≈≈–Ú«∞£∫");
//	print(arr, len);
//	qsort(arr, 10, sizeof(arr[0]), cmp);
//	printf("≈≈–Ú∫Û£∫");
//	print(arr, len);
//
//	return 0;
//}

void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
void swap(char* e1, char* e2, int elementsize)
{
	for (int i = 0; i < elementsize; i++)
	{
		char temp = *e1;
		*e1 = *e2;
		*e2 = temp;
		e1++;
		e2++;
	}
}
void my_qsort(void* base, int len, int elementsize, int (*cmp)(const void* e1, const void* e2))
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (cmp((char*)base+j*elementsize,(char*)base+(j+1)*elementsize) > 0)
			{
				swap((char*)base + j * elementsize, (char*)base + (j + 1) * elementsize, elementsize);
			}
		}
	}
}
int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int main()
{
	int arr[10] = { 5,8,3,4,1,6,10,7,2,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("≈≈–Ú«∞£∫");
	print(arr, len);
	my_qsort(arr, 10, sizeof(arr[0]), cmp);
	printf("≈≈–Ú∫Û£∫");
	print(arr, len);

	return 0;
}