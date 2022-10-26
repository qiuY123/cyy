#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            count++;
        }
        else
        {
            nums[i - count] = nums[i];
        }
    }
    /*for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==val)
        {
            int j=i;
            while(numsSize-j-1)
            {
                nums[j]=nums[j+1];
                j++;
            }

        }
    }*/
    return numsSize - count;
}