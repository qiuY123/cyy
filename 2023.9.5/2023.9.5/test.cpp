#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

void reverse(vector<int>& nums, int left, int right)
{
    while (left < right)
    {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}
void rotate(vector<int>& nums, int k) {
    int count = k % nums.size();
    reverse(nums, 0, nums.size() - count - 1);
    reverse(nums, nums.size() - count, nums.size() - 1);
    reverse(nums, 0, nums.size() - 1);
}

int main()
{



    return 0;
}