#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

int fun(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fun(n - 1) + fun(n - 2);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = fun(n);
    printf("%d", count);
    return 0;
}

#include<stdio.h>
#include<math.h>

int main()
{
    double n = 0.0;
    int m = 0;
    while (scanf("%lf %d", &n, &m) != EOF)
    {
        double sum = 0.0;
        for (int i = 0; i < m; i++)
        {
            sum += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}