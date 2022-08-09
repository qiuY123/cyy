#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<math.h>

//int* printNumbers(int n, int* returnSize) {
//    int x = pow(10, n);
//    for (int i = 0; i < x - 1; i++)
//    {
//        *(returnSize + i) = i + 1;
//    }
//    return returnSize;
//}
//
//int main()
//{
//    int n = 0;
//    int arr[100000];
//    scanf("%d", &n);
//    printNumbers(n, arr);
//    int y = pow(10, n);
//    for (int i = 0; i < y - 1; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

#include<stdio.h>

int main()
{
    int arr[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
    int year = 0;
    int month = 0;
    int day = 0;
    scanf("%d", &year);
    scanf("%d", &month);
    scanf("%d", &day);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        arr[1] = 29;
    }
    else
    {
        arr[1] = 28;
    }
    int sum = 0;
    for (int i = 0; i < month - 1; i++)
    {
        sum += arr[i];
    }
    sum += day;
    printf("%d", sum);
    return 0;
}