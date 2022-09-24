#define _CRT_SECURE_NO_WARNINGS 1 

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int size = 0;
    int arr[100000] = { 0 };
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i])
        {
            count++;
        }
        else
        {
            arr[size] = count;
            size++;
            count = 0;
        }
        if (nums[numsSize - 1] == 1)
        {
            arr[size] = count;
            size++;
        }
    }
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        max = max > arr[i] ? max : arr[i];
    }
    return max;
}

#include<stdio.h>

int is_perfectNumber(int x)
{
    int arr[100] = { 0 };
    int count = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            arr[count] = i;
            count++;
        }
    }
    count = count - 1;//减去它自己，约数至少有两个，一个是 1，一个是 x自己。
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += arr[i];
    }
    if (sum == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int val = is_perfectNumber(i);
        if (val == 1)
        {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}