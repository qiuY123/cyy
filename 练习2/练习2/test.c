#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<math.h>
int main()
{
    int m = 0;
    scanf("%d", &m);
    long long x = pow(m, 3);
    int mid = x / m;
    int count = m / 2;
    int max = 0;
    int min = 0;
    int flag = 0;//判断奇数偶数
    if (m % 2 == 0)
    {
        flag = 2;//偶数
        max = (mid + 1) + 2 * (count - 1);
        min = (mid - 1) - 2 * (count - 1);
    }
    else
    {
        flag = 1;//奇数
        max = mid + 2 * count;
        min = mid - 2 * count;
    }
    for (int i = 0; i < m - 1; i++)
    {
        printf("%d", min + 2 * i);
        printf("+");
    }
    printf("%d", max);
    return 0;
}

#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int arr[1000] = { 0 };
    for (int i = 0; i < n; i++)
    {
        arr[i] = 3 * (i + 1) - 1;
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}