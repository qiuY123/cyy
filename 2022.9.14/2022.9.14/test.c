#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<math.h>
int main()
{
    int x = 0;
    scanf("%d", &x);
    int val = 0;
    int count = 0;
    while (x)
    {
        int temp = x % 10;
        int ret = pow(10, count);
        count++;
        if (temp % 2 == 0)
        {
            temp = 0;
        }
        else
        {
            temp = 1 * ret;
            val += temp;
        }
        x /= 10;
    }
    printf("%d", val);
    return 0;
}

#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[50];
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

#include<stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }

    return 0;
}

#include<stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                printf(" ");
            }
            printf("*\n");

        }
    }

    return 0;
}