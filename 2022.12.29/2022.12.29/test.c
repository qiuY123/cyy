#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

int size(int x)
{
    int size = 0;
    while (x)
    {
        x /= 10;
        size++;
    }
    return size;
}
int get_N_value(int y)
{
    int count = size(y);
    int temp = 1;
    while (count--)
    {
        temp *= 10;
    }
    return y * y % temp;
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == get_N_value(i))
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

#include <stdio.h>

int Is_prime(int value)
{
    if (value < 2)
    {
        return 0;
    }
    for (int i = 2; i < value; i += 1)
    {
        if (value % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (Is_prime(i))
        {
            count++;
        }
    }
    printf("%d", count);
}