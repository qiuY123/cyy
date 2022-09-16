#define _CRT_SECURE_NO_WARNINGS 1 

int is_digit(int val)
{
    if (val < 10)
        return 1;
    else
    {
        return 1 + is_digit(val / 10);
    }
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int count = right - left + 1;
    int size = 0;
    int arr[10000];
    int tmp[10000] = { 0 };
    for (int i = 0; i < count; i++)
    {
        arr[i] = left + i;
    }
    for (int i = 0; i < count; i++)
    {
        int temp = arr[i];
        int digit = is_digit(arr[i]);
        int tp = digit;
        int ret = 0;
        while (tp--)
        {
            int x = temp % 10;
            if (x != 0)
            {
                if (arr[i] % x == 0)
                {
                    ret++;
                }
                temp /= 10;
            }
        }
        if (ret == digit)
        {
            tmp[size] = arr[i];
            size++;
        }
    }
    *returnSize = size;
    int* ans = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        ans[i] = tmp[i];
    }

    return ans;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* arr = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        arr[i] = 1;
    }
    int left = 1;
    int right = 1;
    for (int i = 0; i < numsSize; i++)
    {
        arr[i] *= left;
        arr[numsSize - 1 - i] *= right;
        left *= nums[i];
        right *= nums[numsSize - 1 - i];
    }
    return arr;
}