#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= farthest)
        {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1)
            {
                return true;
            }
        }
    }
    return false;

    // vector<int> dp(nums.size());
    // dp[0]=nums[0];
    // for(int i=1;i<nums.size();i++)
    // {
    //     dp[i]=dp[i-1]+nums[i];
    // }
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(dp[i]!=dp[i+1])
    //     {
    //         if(dp[i]>=nums.size()-1)
    //         {
    //             return true;
    //         }
    //     }
    // }
}

int jump(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int farthest = 0;
    int end = 0;
    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);
        if (i == end)
        {
            end = farthest;
            count++;
        }
    }
    return count;
}

int main()
{


	return 0;
}