#define _CRT_SECURE_NO_WARNINGS 1 

int trailingZeroes(int n) 
{
    int count = 0;
    for (int i = 1; pow(5, i) <= n; i++) 
    {
        count += (int)(n / pow(5, i));
    }
    return count;
}

#include <stdio.h>

int main()
{
    double value;
    scanf("%lf", &value);
    printf("%d", (int)(value + 0.5));
    return 0;
}