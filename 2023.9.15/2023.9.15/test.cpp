#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSubsequence(string s, string t) {
    if (s.size() == 0)
    {
        return true;
    }
    int n1 = s.size();
    int n2 = t.size();
    int i = 0;
    int j = 0;
    while (j < n2)
    {
        if (s[i] == t[j])
        {
            i++;
            if (i == n1)
            {
                return true;
            }
        }
        j++;
    }
    return false;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> v;
    v.reserve(2);
    int n = numbers.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
        else if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else
        {
            break;
        }
    }
    return v = { left + 1,right + 1 };
}

int main()
{


	return 0;
}