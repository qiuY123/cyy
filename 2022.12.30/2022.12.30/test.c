#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<stdbool.h>

int FirstNotRepeatingChar(char* str)
{
    // write code here
    int arr[128] = { 0 };
    int sz = strlen(str);
    for (int i = 0; i < sz; i++)
    {
        arr[str[i]] += 1;
    }
    for (int i = 0; i < sz; i++)
    {
        if (arr[str[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

bool isUnique(char* astr)
{
    int arr[128] = { 0 };
    int sz = strlen(astr);
    for (int i = 0; i < sz; i++)
    {
        arr[astr[i]] += 1;
    }
    for (int j = 0; j < 128; j++)
    {
        if (arr[j] > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char arr[20] = { "leetcode" };
    isUnique(arr);
    return 0;
}