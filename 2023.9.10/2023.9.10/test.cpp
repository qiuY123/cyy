#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && ratings[i] > ratings[i - 1])
        {
            tmp[i] = tmp[i - 1] + 1;
        }
        else
        {
            tmp[i] = 1;
        }
    }
    int ret = 0, temp = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i<n - 1 && ratings[i]>ratings[i + 1])
        {
            temp++;
        }
        else
        {
            temp = 1;
        }
        ret += max(tmp[i], temp);
    }
    return ret;
}

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> v(n);

    int sum1 = 0;
    int sum2 = 0;

    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        if (height[i] != 0)
        {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (height[i] != 0)
        {
            right = i;
            break;
        }
    }

    v[left] = height[left];
    v[right] = height[right];

    int ret = min(height[left], height[right]);

    int l = left + 1, r = right - 1;
    while (l <= r)
    {
        v[l++] = ret;
    }

    int prevleft = left, prevright = right;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            left++;
            if (left == right)
            {
                break;
            }
            if (height[left] >= height[prevleft])
            {
                prevleft = left;
                ret = min(height[left], height[right]);
                v[left] = height[left];
                v[right] = height[right];
                int l = left + 1, r = right - 1;
                while (l <= r)
                {
                    v[l++] = ret;
                }
            }
        }
        else
        {
            right--;
            if (left == right)
            {
                break;
            }
            if (height[prevright] <= height[right])
            {
                prevright = right;
                ret = min(height[left], height[right]);
                v[left] = height[left];
                v[right] = height[right];
                int l = left + 1, r = right - 1;
                while (l <= r)
                {
                    v[l++] = ret;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum1 += height[i];
        sum2 += v[i];
    }
    return sum2 - sum1;
}

int main()
{
    vector<int> v{ 5,4,1,2 };
    trap(v);

	return 0;
}