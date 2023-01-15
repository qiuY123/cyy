#define _CRT_SECURE_NO_WARNINGS 1 

char str[10][201];

char* sortSentence(char* s)
{
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int i;
    int j = 0;
    int index = 0;
    res[0] = '\0';

    for (i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            memcpy(str[s[i - 1] - '1'], s + j, i - j - 1);
            str[s[i - 1] - '1'][i - j - 1] = ' ';
            str[s[i - 1] - '1'][i - j] = '\0';
            j = i + 1;
            index++;
        }
    }
    for (j = 0; j < index; j++)
    {
        strcat(res, str[j]);
    }

    int sz = strlen(res);
    res[sz - 1] = '\0';
    return res;
}

int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int findLHS(int* nums, int numsSize) 
{       
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int ret = 0;
    int begin = 0;
    for (int end = 0; end < numsSize; end++) 
    {
        if (nums[end] - nums[begin] > 1) 
        { 
            begin++;
        }
        if (nums[end] - nums[begin] == 1) 
        { 
            ret = fmax(ret, end - begin + 1);
        }
    }
    return ret;
}

