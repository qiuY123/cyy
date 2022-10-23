#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

void reverse(int* arr, int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    /*while(k--)
    {
        int temp=nums[numsSize-1];
        for(int i=1;i<numsSize;i++)
        {
            nums[numsSize-i]=nums[numsSize-i-1];
        }
        nums[0]=temp;
    }*/
    int x = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, x - 1);
    reverse(nums, x, numsSize - 1);
}

int missingNumber(int* nums, int numsSize)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum1 += nums[i];
        sum2 += i;
    }
    sum2 += numsSize;
    int value = sum2 - sum1;
    return value;
}