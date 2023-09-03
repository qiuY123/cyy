#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = m - n - 1, b = n - 1;
    for (int i = m - 1; i >= 0; i--)
    {
        if (a == -1)
        {
            nums1[i] = nums2[b--];
            continue;
        }
        if (b == -1)
        {
            break;
        }

        if (nums1[a] >= nums2[b])
        {
            nums1[i] = nums1[a--];
        }
        else
        {
            nums1[i] = nums2[b--];
        }
    }
}



int main()
{
    vector<int> v1 = { 1,2,3,0,0,0 };
    vector<int> v2 = { 2,5,6 };

    merge(v1, v1.size(), v2, v2.size());

	return 0;
}