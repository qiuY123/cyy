#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>
////µİ¹é
//int Fib1(int n)
//{
//	if(n<=2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib1(n - 1) + Fib1(n - 2);
//	}
//}
////·Çµİ¹é
//int Fib2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int sum = 0;
//	while (n > 2)
//	{
//		sum = a + b;
//		a = b;
//		b = sum;
//		n--;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int value1 = Fib1(n);
//	int value2 = Fib2(n);
//	printf("%d\n", value1);
//	printf("%d\n", value2);
//	return 0;
//}
////µİ¹é
//int my_strlen1(char* arr)
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen1(arr + 1);
//	}
//}
////·Çµİ¹é
//int my_strlen2(char* arr)
//{
//	int count = 0;
//	while (*arr)
//	{
//		arr++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int len1 = my_strlen1(arr);
//	int len2 = my_strlen2(arr);
//	printf("%d\n", len1);
//	printf("%d\n", len2);
//	return 0;
//}
//void reverse_string(char* arr)
//{
//	int len = strlen(arr);
//	if (*arr == '\0')
//	{
//		return;
//	}
//	else
//	{
//		char temp = arr[0];
//		arr[0] = arr[len - 1];
//		arr[len - 1] = '\0';
//		reverse_string(arr + 1);
//		arr[len - 1] = temp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	printf("%s\n", arr);
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//
//int DigitSum(int n)
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	else
//	{
//		return (n % 10) + DigitSum(n / 10);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = DigitSum(n);
//	printf("%d\n", sum);
//	return 0;
//}
//
//int power(int n,int k)
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return n * power(n, k - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int value = power(n, k);
//	printf("%d", value);
//	return 0;
//}
//int Acc(int n)
//{
//    if (n == 1)
//    {
//        return 1;
//    }
//    else
//    {
//        return n + Acc(n - 1);
//    }
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int ret = Acc(n);
//    printf("%d\n", ret);
//    return 0;
//}
#include<stdio.h>
int main()
{
    int n = 0;
    int x = 0;
    int sum = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &x);
        sum = sum + x;;
    }
    printf("%d", sum);
    return 0;
}