#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include<string.h>

int main()
{
    int n = 0;
    char ret[100];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", ret);
        int sz = strlen(ret);
        if (sz < 10)
        {
            printf("%s\n", ret);
        }
        else
        {
            printf("%c%d%c\n", ret[0], sz - 2, ret[sz - 1]);
        }
    }
    return 0;
}

char* replaceSpaces(char* S, int length) 
{
    char* tmp = malloc(sizeof(char) * (length * 3 + 1));
    int n = 0;
    while (length--) 
    {
        if (*S == ' ') 
        {
            tmp[n++] = '%';
            tmp[n++] = '2';
            tmp[n++] = '0';
        }
        else 
        {
            tmp[n++] = *S;
        }
        S++;
    }
    tmp[n] = 0;
    return tmp;
}

