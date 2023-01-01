#define _CRT_SECURE_NO_WARNINGS 1 

bool CheckPermutation(char* s1, char* s2)
{
    int arr1[128] = { 0 };
    int arr2[128] = { 0 };
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
    {
        return false;
    }
    for (int i = 0; i < len1; i++)
    {
        arr1[s1[i]] += 1;
    }
    for (int i = 0; i < len2; i++)
    {
        arr2[s2[i]] += 1;
    }
    for (int i = 0; i < 128; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

bool canPermutePalindrome(char* s)
{
    int arr[128] = { 0 };
    int sz = strlen(s);
    for (int i = 0; i < sz; i++)
    {
        arr[s[i]] += 1;
    }
    for (int i = 0; i < 128; i++)
    {
        arr[i] %= 2;
    }
    int sum = 0;
    for (int i = 0; i < 128; i++)
    {
        sum += arr[i];
    }
    if (sum > 1)
    {
        return false;
    }
    return true;
}