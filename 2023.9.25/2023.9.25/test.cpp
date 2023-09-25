#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                v.push_back(i);
                v.push_back(j);
                break;
            }
        }
        if (v.size() == 2)
        {
            break;
        }
    }
    return v;
}

int sumval(int n)
{
    int sum = 0;
    int tmp = 0;
    while (n)
    {
        tmp = pow(n % 10, 2);
        n /= 10;
        sum += tmp;
    }
    return sum;
}
bool isHappy(int n) {
    int cur = n;
    int next = sumval(n);
    while (cur != next)
    {
        cur = sumval(cur);
        next = sumval(sumval(next));
    }
    if (cur == 1)
    {
        return true;
    }
    return false;
}


int main()
{

    return 0;
}