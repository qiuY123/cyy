#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) 
{
    vector<vector<int>>v(numRows);    //定义一个二维数组  有numRows行数

    for (int i = 0; i < numRows; i++)
    {
        v[i].resize(i + 1, 1);  //初始化每一行的内存，并赋值为1
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
        }
    }

    return v;

}

int maxProduct(vector<int>& nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}

int main()
{

	return 0;
}