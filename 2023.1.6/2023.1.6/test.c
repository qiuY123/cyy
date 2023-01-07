#define _CRT_SECURE_NO_WARNINGS 1 

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        ret[i] = 0;
        int tmp = i;
        while (tmp > -1)
        {
            ret[i] += nums[tmp--];
        }

    }

    return ret;
}

int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > target)
        {
            return i;
        }
    }
    //if(target>nums[numsSize-1])
    return numsSize;
}