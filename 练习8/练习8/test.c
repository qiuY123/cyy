#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<string.h>

int main()
{
    char arr[500];
    int str[127] = { 0 };
    scanf("%s", arr);
    int len = strlen(arr);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        int x = (int)arr[i];
        if (str[x] == 0)
        {
            str[x] = 1;
            count++;
        }
    }
    printf("%d", count);

    return 0;
}

int majorityElement(int* nums, int numsSize) {
    int value = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            value = nums[i];
            count = 1;
        }
        else if (value == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return value;
}