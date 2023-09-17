#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

int minSubArrayLen(int target, std:: vector<int>& nums) {
    int ret = INT_MAX;
    int left = 0, right = 0;
    int n = nums.size();
    long long sum = 0;
    while (right < n)
    {
        sum += nums[right];
        while (sum >= target)
        {
            ret = std::min(ret, right - left + 1);
            sum -= nums[left++];
        }
        right++;
    }
    return ret == INT_MAX ? 0 : ret;
}

//int lengthOfLongestSubstring(std::string s) {
//    int n = s.size();
//    int ret = 0;
//    std::map<char, int> m;
//    int left = 0, right = 0;
//    for (; right < n; right++)
//    {
//        m[s[right]]++;
//        if (m[s[right]] == 2)
//        {
//            m[s[right]]--;
//            ret = std::max(ret, right - left + 1);
//            while (1)
//            {
//                if (s[left++] == s[right])
//                {
//                    break;
//                }
//            }
//        }
//    }
//    return ret;
//}

int lengthOfLongestSubstring(std::string s) {
    int n = s.size();
    int ret = 0;
    std::map<char, int> m;
    int left = 0, right = 0;
    for (; right < n; right++)
    {
        m[s[right]]++;
        while (m[s[right]] > 1)
        {
            m[s[left++]]--;
        }
        ret = std::max(ret, right - left + 1);
    }
    return ret;
}

int main()
{
    /*std::vector<int> v = { 1,2,3,4,5};
    minSubArrayLen(11, v);*/
    std::string s = "abcabcbb";
    lengthOfLongestSubstring(s);
	return 0;
}
