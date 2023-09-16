#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int maxArea(std::vector<int>& height) {
    int ret = 0;
    int n = height.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        ret = height[left] < height[right] ?
            std::max(ret, (right - left) * height[left++]) :
            std::max(ret, (right - left) * height[right--]);
    }
    return ret;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> arr;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            break;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > -nums[i])
            {
                right--;
            }
            else if (sum < -nums[i])
            {
                left++;
            }
            else
            {
                arr.push_back({ nums[i],nums[left],nums[right] });
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1])
                {
                    right--;
                }
            }
        }
    }

    return arr;
}

int main()
{


	return 0;
}
