#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<math.h>

//int sumvalue(int x,int n)
//{
//	int m = n;
//	if (n == 0)
//	{
//		return x;
//	}
//	else
//	{
//		int y = 0;
//		while (m)
//		{
//			y = y + x * pow(10, m);
//			m--;
//		}
//		y = y + x;
//		return y + sumvalue(x, n - 1);
//	}
//}
//
//int main()
//{
//	int x = 0;
//	int n = 0;
//	scanf("%d %d", &x, &n);
//	int sum = sumvalue(x, n - 1);
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//
//	for (int i = 0; i <= 100000; i++)
//	{
//		int temp1 = i;
//		int temp2 = i;
//		int sum = 0;
//		int count = 1;
//		while (temp1 = temp1 / 10)
//		{
//			count++;
//		}
//		while (temp2)
//		{
//			sum += pow(temp2 % 10, count);
//			temp2 /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;

//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    int arr[10][10] = { 0 };
//    int x;
//    int sum = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d ", &x);
//            arr[i][j] = x;
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            sum += arr[i][j];
//        }
//    }
//    if (sum == 0)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}

//void fun(int x)
//{
//    if (x < 6)
//    {
//        printf("%d", x);
//    }
//    else
//    {   
//        fun(x / 6);
//        printf("%d", x % 6);
//    }
//}
//int main()
//{
//    int x = 0;
//    scanf("%d", &x);
//    fun(x);
//    return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//    int arr1[50] = { 0 };
//    int arr2[50] = { 0 };
//    int j = 0;
//    int n = 0;
//    scanf("%d", &n);
//    int x = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d ", &x);
//        arr1[i] = x;
//    }
//    int y = 0;
//    scanf("%d", &y);
//    int count = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (arr1[i] != y)
//        {
//            count++;
//            arr2[j++] = arr1[i];
//        }
//    }
//    for (int i = 0; i < count; i++)
//    {
//        printf("%d ", arr2[i]);
//    }
//    return 0;
//}
//
//#include<stdio.h>
//
//int main()
//{
//    long long a, b;
//    scanf("%ld %ld", &a, &b);
//    long long max = a > b ? a : b;
//    long long min = a < b ? a : b;
//    while (min)
//    {
//        long long temp = max % min;
//        max = min;
//        min = temp;
//    }
//    min = a * b / max;
//    printf("%ld", max + min);
//    return 0;
//}

#include<stdio.h>

int fun(int ret)
{
    int a = 1;
    int b = 1;
    int c = 1;
    if (ret <= 2)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < ret - 1; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}
int main()
{
    int ret = 0;
    scanf("%d", &ret);
    int value = fun(ret);
    printf("%d", value);
    return 0;
}