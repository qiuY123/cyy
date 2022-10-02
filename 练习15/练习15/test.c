#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

int main()
{
    int val = 0;
    int n = 0;
    int arr[2000000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        val ^= arr[i];
    }
    printf("%d", val);
    return 0;
}

int findPeakElement(int* nums, int numsLen) {
    // write code here
    if (nums[0] > nums[1])
        return 0;
    else if (nums[numsLen - 1] > nums[numsLen - 2])
        return numsLen - 1;
    for (int i = 0; i < numsLen - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return i;
    }
    return -1;
}