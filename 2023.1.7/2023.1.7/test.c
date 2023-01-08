#define _CRT_SECURE_NO_WARNINGS 1 

int search(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int getDecimalValue(struct ListNode* head)
{
    int value = 0;
    struct ListNode* tmp = head;
    int count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    while (head)
    {
        value += head->val * pow(2, --count);
        head = head->next;
    }
    return value;
}