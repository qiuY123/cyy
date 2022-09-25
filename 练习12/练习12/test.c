#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<string.h>

int main()
{
    char str[30];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100][22];
    int i = 0;
    int x;
    while (1)
    {
        x = scanf("%[a-z|A-Z]", str[i]);
        if (getchar() == '\n')
            break;
        if (x)
            i++;
    }
    for (int j = i; j >= 0; j--)
    {
        printf("%s ", str[j]);
    }
    return 0;
}