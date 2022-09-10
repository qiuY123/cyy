#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
#include<string.h>
int main()
{
    char arr[1000];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("%s", arr);
    return 0;
}

int pivotIndex(int* nums, int numsSize) {
    int j = -1;
    for (int i = 0; i < numsSize; i++)
    {
        int count1 = i;
        int count2 = i;
        int sum1 = 0;
        int sum2 = 0;
        while (count1--)
        {
            sum1 += nums[count1];
        }
        while (count2 < numsSize)
        {
            count2++;
            if (count2 < numsSize)
                sum2 += nums[count2];
        }
        if (sum1 == sum2)
        {
            j = i;
            break;
        }
    }
    return j;
}