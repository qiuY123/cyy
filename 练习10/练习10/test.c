#define _CRT_SECURE_NO_WARNINGS 1 

int Add(int num1, int num2) {
    // write code here
    while (num1)
    {
        int temp = (num1 & num2) << 1;
        num2 ^= num1;
        num1 = temp;
    }
    return num2;
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    int temp[100000] = { 0 };
    for (int i = 0; i < numsSize; i++)
    {
        temp[i] = i + 1;
    }
    int ans[100000] = { 0 };
    for (int i = 0; i < numsSize; i++)
    {
        int size = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (temp[i] == nums[j])
            {
                size++;
            }
        }
        if (size == 0)
        {
            ans[count] = temp[i];
            count++;
        }
    }
    *returnSize = count;
    int* arr = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        arr[i] = ans[i];
    }

    return arr;
}