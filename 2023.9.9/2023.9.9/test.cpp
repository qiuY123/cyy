#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> bp(n), ep(n);
    bp[0] = 1;
    ep[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        bp[i] = bp[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ep[i] = ep[i + 1] * nums[i + 1];
    }
    vector<int> ret(n);
    for (int i = 0; i < n; i++)
    {
        ret[i] = bp[i] * ep[i];
    }
    return ret;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0, total_gas = 0, current_gas = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        current_gas += gas[i] - cost[i];
        total_gas += gas[i] - cost[i];
        if (current_gas < 0)
        {
            start = i + 1;
            current_gas = 0;
        }
    }
    return total_gas >= 0 ? start : -1;
}

int main()
{



	return 0;
}