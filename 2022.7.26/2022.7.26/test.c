#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>

//void swap(int* arr1, int* arr2, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		/*int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;*/
//		int temp = *(arr1 + i);
//		*(arr1 + i) = *(arr2 + i);
//		*(arr2 + i) = temp;
//	}
//}
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 6,7,8,9,10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	printf("交换前：\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	swap(arr1, arr2, sz);
//	printf("交换后：\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//void Init(int* arr,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		*(arr + i) = i;
//	}
//}
//void print(int* arr,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//}
//void reverse(int* arr,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while(left < right)
//	{
//		int temp = *(arr + left);
//		*(arr + left) = *(arr + right);
//		*(arr + right) = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz);
//	printf("初始化打印：\n");
//	print(arr, sz);
//	printf("逆置后打印：\n");
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}
//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void print(int* arr,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = { 2,4,7,4,1,3,8,9,22,15 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("排序前：\n");
//	print(arr, sz);
//	printf("排序后：\n");
//	bubble_sort(arr, sz);
//	print(arr, sz);
//}
//int main()
//{
//    int M = 0;
//    int N = 0;
//    int x = 0;
//    int sum = 0;
//    scanf("%d %d", &N, &M);
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < M; j++)
//        {
//            scanf("%d ", &x);
//            if (x > 0)
//                sum = sum + x;
//        }
//    }
//    printf("%d\n", sum);
//    return 0;
//}
int main()
{

    int n, m;
    int x = 0;
    int arr[10][10] = { 0 };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d ", &x);
            arr[i][j] = x;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }

    return 0;

}