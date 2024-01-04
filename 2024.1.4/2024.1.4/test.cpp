#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> v(spells.size());
    for (int i = 0; i < spells.size(); i++)
    {
        double tmp = success * 1.0 / spells[i];
        if (tmp * potions[0] >= success)
        {
            v[i] = potions.size();
            continue;
        }
        int l = 0, r = potions.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (tmp * potions[mid] >= success && tmp * potions[mid - 1] < success)
            {
                v[i] = potions.size() - mid;
                break;
            }
            else if (tmp * potions[mid] >= success && tmp * potions[mid - 1] > success)
            {
                r = mid - 1;
            }
            else if (tmp * potions[mid] < success)
            {
                l = mid + 1;
            }
        }
    }
    return v;
    // sort(potions.begin(), potions.end());
    // vector<int> ans;
    // int m = potions.size();
    // for (int& v : spells) {
    //     int i = lower_bound(potions.begin(), potions.end(), success * 1.0 / v) - potions.begin();
    //     ans.push_back(m - i);
    // }
    //return ans;
}

int minEatingSpeed(vector<int>& piles, int h) {
    sort(piles.begin(), piles.end());
    int n = piles.size();
    int l = 1, r = piles[n - 1];
    while (l < r) {
        int mid = (l + r) >> 1;
        int custome = 0;
        for (int i = 0; i < n; ++i) {
            if (piles[i] % mid) ++custome;
            custome += (piles[i] / mid);
        }
        if (h < custome) l = mid + 1;
        else if (h >= custome) r = mid;
    }
    return r;
}

int main()
{


	return 0;
}