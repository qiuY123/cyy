#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int ret = 0;
    int n = citations.size();
    for (int i = 0; i < n; i++)
    {
        if (citations[i] >= n - i)
        {
            ret++;
        }
    }
    return ret;
}

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if (m.count(val))
        {
            return false;
        }
        int pos = nums.size();
        nums.push_back(val);
        m[val] = pos;
        return true;
    }

    bool remove(int val) {
        if (!m.count(val))
        {
            return false;
        }
        int pos = m[val];
        int ret = nums.back();
        nums[pos] = ret;
        m[ret] = pos;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() {
        int randpos = rand() % nums.size();
        return nums[randpos];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};

int main()
{



	return 0;
}
