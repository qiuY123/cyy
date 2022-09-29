#define _CRT_SECURE_NO_WARNINGS 1 

int* masterMind(char* solution, char* guess, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(*returnSize * sizeof(int));
    int right = 0;
    int flaseright = 0;
    for (int i = 0; i < 4; i++)
    {
        if (solution[i] == guess[i])
        {
            right++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (solution[i] == guess[j])
            {
                flaseright++;
                guess[j] = '0';
                break;
            }

        }
    }
    ans[0] = right;
    ans[1] = flaseright - right;

    return ans;
}

int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    // write code here
    *returnSize = 2;
    int* arr = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numbersLen; i++)
    {
        for (int j = 0; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                if (i < j)
                {
                    arr[0] = i + 1;
                    arr[1] = j + 1;
                }
                else if (i > j)
                {
                    arr[0] = j + 1;
                    arr[1] = i + 1;
                }
            }
        }
    }
    return arr;
}
