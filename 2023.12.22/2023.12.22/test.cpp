#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0, zerosize = 0, maxlen = 0;
    while (r < n)
    {
        if (nums[r++] == 0)
        {
            zerosize++;
        }
        while (zerosize > 1)
        {
            if (nums[l++] == 0)
            {
                zerosize--;
            }
        }
        maxlen = max(maxlen, r - l - 1);
    }
    return maxlen;
}

int largestAltitude(vector<int>& gain) {
    int ans = 0, h = 0;
    for (int v : gain)
    {
        h += v;
        ans = max(ans, h);
    }
    return ans;

}

int main()
{

	return 0;
}