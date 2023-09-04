#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

//int removeDuplicates(vector<int>& nums) {
//    vector<int>::iterator it = nums.begin() + 1;
//    while (it != nums.end())
//    {
//        if (*it == *(it - 1))
//        {
//            nums.erase(it);
//        }
//        else
//        {
//            it++;
//        }
//    }
//    return nums.size();
//}

int removeDuplicates(vector<int>& nums) {
    int removeDuplicates(vector<int>&nums) {
        if (nums.size() <= 2)
        {
            return nums.size();
        }
        vector<int>::iterator it = nums.begin();
        int left = 0, right = 1;
        while (1)
        {
            if ((it + right) == nums.end())
            {
                break;
            }

            if (*(it + left) == *(it + right))
            {
                right++;
            }

            if ((it + right) == nums.end())
            {
                break;
            }

            if (right - left >= 2)
            {
                if (*(it + left) == *(it + right))
                {
                    nums.erase(it + right);
                    right--;
                }
            }

            if (*(it + left) != *(it + right))
            {
                left = right;
                right++;
            }
        }
        return nums.size();
    }
}

int main()
{
    vector<int> v = { 1,1,1,2,2,3 };
    removeDuplicates(v);
	return 0;
}