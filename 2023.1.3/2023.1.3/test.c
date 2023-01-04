#define _CRT_SECURE_NO_WARNINGS 1 

int multiply(int A, int B) {
    if (B) 
    {
        if (B & 1)
        {
            return multiply((long long)A << 1, B >> 1) + A;
        }
        else
        {
            return multiply((long long)A << 1, B >> 1);
        }
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    int tmp = 0;
    for (int i = 0; i <= n; i++)
    {
        tmp = i;
        while (tmp)
        {
            int a = tmp % 10;
            tmp = tmp / 10;
            if (i % 7 == 0 || a == 7 || tmp == 7)
            {
                count++;
                break;
            }
        }
    }
    printf("%d", count);
}