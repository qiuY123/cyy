#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

// bool dfs(vector<int>& nums,int target,int i)
    // {
    //     if(target==0)
    //     {
    //         return true;
    //     }
    //     else if(target<0)
    //     {
    //         return false;
    //     }
    //     target-=nums[i];
    //     dfs(nums,target,i+1);
    //     target+=nums[i];
    // }
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto& e : nums) {
        sum += e;
    }
    if (sum % 2)
    {
        return false;
    }
    int target = sum / 2;
    //dfs(nums,target,0);
    vector<int> dp(target + 1);
    for (auto x : nums)
    {
        for (int i = target; i >= x; i--)
        {
            dp[i] = max(dp[i], dp[i - x] + x);
        }
    }
    return dp[target] == target;
}

int longestValidParentheses(string s) {
    int n = s.size();
    vector<int> dp(n, 0);
    int maxlen = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxlen = max(maxlen, dp[i]);
        }
    }

    return maxlen;
    // stack<char> st;
    // int count=0;
    // for(auto& e:s)
    // {
    //     if(e=='(')
    //     {
    //         st.push(e);
    //     }
    //     if(!st.empty()&&e==')')
    //     {
    //         st.pop();
    //         count+=2;
    //     }
    // }
    //return count;
}

int main()
{

	return 0;
}