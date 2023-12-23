#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> vv(2);
    unordered_set<int> uset1, uset2;
    for (int i = 0; i < nums1.size(); i++)
    {
        uset1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        uset2.insert(nums2[i]);
    }
    for (int e : uset1)
    {
        if (!uset2.count(e))
        {
            vv[0].push_back(e);
        }
    }
    for (int e : uset2)
    {
        if (!uset1.count(e))
        {
            vv[1].push_back(e);
        }
    }
    return vv;
}

bool uniqueOccurrences(vector<int>& arr) {
    int hash[2000] = { 0 };
    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i] + 1000]++;
    }
    unordered_set<int> uset;
    for (int i = 0; i < arr.size(); i++)
    {
        uset.insert(arr[i]);
    }
    unordered_map<int, int> ump;
    for (int e : uset)
    {

        ump[hash[e + 1000]]++;

        if (ump[hash[e + 1000]] != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{

	return 0;
}