#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int maxsum = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
        maxsum = sum;
    }
    int j = 0;
    for (int i = k; i < nums.size(); i++)
    {
        sum -= nums[j++];
        sum += nums[i];
        maxsum = max(maxsum, sum);
    }
    return (double)maxsum / k;
}

int maxVowels(string s, int k) {
    int maxcount = 0;
    int n = s.size();

    int hash[26] = { 0 };
    hash['a' - 'a'] = 1;
    hash['e' - 'a'] = 1;
    hash['i' - 'a'] = 1;
    hash['o' - 'a'] = 1;
    hash['u' - 'a'] = 1;

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (hash[s[i] - 'a'] == 1)
        {
            count++;
        }
    }
    maxcount = count;
    int j = 0;
    for (int i = k; i < n; i++)
    {
        if (hash[s[j++] - 'a'])
        {
            count--;
        }
        if (hash[s[i] - 'a'])
        {
            count++;
        }
        maxcount = max(maxcount, count);
    }
    return maxcount;
}

int main()
{

	return 0;
}