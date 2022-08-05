#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>

//void adjust(int* arr,int len)
//{
//	for (int j = 0; j < len; j++)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			int count = i;
//			if (*(arr + count) % 2 == 0)
//			{
//				int temp = *(arr + count);
//				while (count < len - 1)
//				{
//					*(arr + count) = *(arr + count + 1);
//					count++;
//				}
//				*(arr + len - 1) = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 5,7,8,9,10,6,8,4,2,1,0 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	printf("交换前：");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	adjust(arr, len);
//	printf("交换后：");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//char* my_strcpy(char* dest,const char* src )
//{
//	while (*dest++ = *src++)
//	{
//
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[20]="000000000";
//	char arr2[] = "abcdefg";
//	printf("拷贝前：");
//	printf("%s\n", arr1);
//	my_strcpy(arr1, arr2);
//	printf("拷贝后：");
//	printf("%s\n", arr1);
//	return 0;
//}
//
//unsigned int my_strlen(char* arr)
//{
//	unsigned int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdefghi";
//	printf("%d\n",my_strlen(arr));
//	return 0;
//}
//
//int main()
//{
//    int n = 0;
//    int val = 0;
//    int arr[50] = { 0 };
//    scanf("%d", &n);
//    int count = n;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d ", &val);
//        arr[i] = val;
//    }
//    int j = 0;
//    int i = 0;
//    while (--count)
//    {
//        if (arr[j] >= arr[j + 1])
//        {
//            if (j < n - 2)
//            {
//                j++;
//            }
//        }
//        else
//        {
//            j--;
//        }
//        if (arr[i] <= arr[i + 1])
//        {
//            if (i < n - 2)
//            {
//                i++;
//            }
//        }
//        else
//        {
//            i--;
//        }
//    }
//    if (j == n - 2 || i == n - 2)
//    {
//        printf("sorted");
//    }
//    else
//    {
//        printf("unsorted");
//    }
//    return 0;
//}

#include<stdio.h>

int main()
{
    int n = 0;
    int score = 0;
    int arr[10000] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &score);
        arr[i] = score;
    }
    int max = arr[0];
    int min = arr[0];
    for (int j = 0; j < n; j++)
    {
        max = max > arr[j] ? max : arr[j];
    }
    for (int j = 0; j < n; j++)
    {
        min = min < arr[j] ? min : arr[j];
    }
    int value = max - min;
    printf("%d", value);
    return 0;
}