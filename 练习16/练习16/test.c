#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

int main()
{
    int count = 0;
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int arr[2] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[0] = i;
            arr[1] = j;
            if (arr[0] % arr[1] >= k)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}

#include<stdio.h>

int main()
{
    char ch[1000] = { 0 };
    char* p = ch;
    scanf("%s", ch);
    int len = strlen(ch);
    int k = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        printf("%c", *(p + i));
    }
    return 0;
}