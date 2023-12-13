#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

template<class T>
struct cmp
{
    bool operator()(const T& e1, const T& e2)
    {
        return e1.second > e2.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    // unordered_map<int,int> ump;
    // for(int i=0;i<nums.size();i++)
    // {
    //     ump[nums[i]]++;
    // }
    // vector<pair<int,int>> vp;
    // for(auto e:ump)
    // {
    //     vp.push_back(e);
    // }
    // sort(vp.begin(),vp.end(),cmp<pair<int,int>>());
    // vector<int> vi;
    // for(int i=0;i<k;i++)
    // {
    //     vi.push_back(vp[i].first);
    // }
    // return  vi;
     //1.map记录元素出现的次数
    unordered_map<int, int>map;
    for (auto& c : nums) {
        map[c]++;
    }
    struct myComparison {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;//小顶堆是大于号
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> q;
    for (auto& a : map) {
        q.push(a);
        if (q.size() > k) {
            q.pop();
        }
    }

    vector<int>res;
    while (!q.empty()) {
        res.emplace_back(q.top().first);
        q.pop();
    }
    return res;
}

vector<int> partitionLabels(string s) {
    int last[26];
    int length = s.size();
    for (int i = 0; i < length; i++) {
        last[s[i] - 'a'] = i;
    }
    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            partition.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return partition;
}

int main()
{

	return 0;
}
