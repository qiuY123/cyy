#define _CRT_SECURE_NO_WARNINGS 1 

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* arr = (int*)malloc(*returnSize * sizeof(int));
    int x = 0;
    long long sum = 0;
    long long value = (1 + numsSize) * numsSize / 2;
    for (int k = 0; k < numsSize; k++)
    {
        sum += nums[k];
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i != j)
            {
                x = nums[i] ^ nums[j];
            }
            if (x == 0)
            {
                arr[0] = nums[i];
                if (sum > value)
                    arr[1] = arr[0] + value - sum;
                else if (sum < value)
                    arr[1] = arr[0] - sum + value;
            }
        }
    }
    return arr;
}

#include<stdio.h>
#include<string.h>
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            char arr[200] = { 0 };
            scanf("%s", arr);
            int big = 0;
            int small = 0;
            int num = 0;
            int count = 0;
            if (arr[0] >= '0' && arr[0] <= '9')
            {
                printf("NO\n");
                break;
            }
            if (strlen(arr) < 8)
            {
                printf("NO\n");
                break;
            }
            for (int i = 0; arr[i] != '\0'; i++)
            {
                if (arr[i] >= '0' && arr[i] <= '9')
                {
                    num++;
                }
                else if (arr[i] >= 'a' && arr[i] <= 'z')
                {
                    small++;
                }
                else if (arr[i] >= 'A' && arr[i] <= 'Z')
                {
                    big++;
                }
                else
                {
                    count++;
                }
            }
            if (count != 0)
            {
                printf("NO\n");
                break;
            }
            if ((big > 0) + (small > 0) + (num > 0) >= 2)
            {
                printf("YES\n");
                break;
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}