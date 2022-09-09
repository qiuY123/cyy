#define _CRT_SECURE_NO_WARNINGS 1 

int dominantIndex(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;
    int biggest = nums[0];
    int bigger = 0;
    int pos = 0;
    for (int i = 0; i < numsSize; i++)
    {
        biggest = biggest > nums[i] ? biggest : nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (biggest == nums[i])
        {
            pos = i;
        }
    }
    if (pos < numsSize - 1)
    {
        bigger = nums[pos + 1];
    }
    else
    {
        bigger = nums[pos - 1];
    }
    for (int j = 0; j < numsSize; j++)
    {
        if (j != pos)
        {
            bigger = bigger > nums[j] ? bigger : nums[j];
        }
    }
    if (bigger != 0)
    {
        if (biggest / bigger < 2)
        {
            pos = -1;
        }
    }

    return pos;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = i + 1; j < nums1Size; j++)
        {
            if (nums1[i] == nums1[j])
            {
                int n = i;
                while (nums1Size - n - 1)
                {
                    nums1[n] = nums1[n + 1];
                    n++;
                }
                nums1Size--;
                j--;
            }
        }
    }
    for (int i = 0; i < nums2Size; i++)
    {
        for (int j = i + 1; j < nums2Size; j++)
        {
            if (nums2[i] == nums2[j])
            {
                int n = i;
                while (nums2Size - n - 1)
                {
                    nums2[n] = nums2[n + 1];
                    n++;
                }
                nums2Size--;
                j--;
            }
        }
    }
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                count++;
                break;
            }
        }
    }
    int pos[1000] = { 0 };
    int k = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                pos[k] = i;
                k++;
                break;
            }
        }
    }
    *returnSize = count;
    int* arr = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        arr[i] = nums1[pos[i]];
    }
    return arr;
}