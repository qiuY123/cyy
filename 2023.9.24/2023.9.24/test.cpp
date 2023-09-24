#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool isAnagram(string s, string t) {
    int m = s.size(), n = t.size();
    if (m != n)
    {
        return false;
    }
    int hash1[26] = { 0 };
    int hash2[26] = { 0 };
    for (int i = 0; i < m; i++)
    {
        hash1[s[i] - 'a']++;
        hash2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash1[i] != hash2[i])
        {
            return false;
        }
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> vvs;
    int n = strs.size();
    vvs.reserve(n);

    vector<int> v(n, 0);//标记

    for (int i = 0; i < n - 1; i++)
    {
        vector<string> vs;
        for (int j = i; j < n; j++)
        {
            if (isAnagram(strs[i], strs[j]) && !v[j])
            {
                v[j] = 1;
                vs.push_back(strs[j]);
            }
        }
        if (vs.size())
            vvs.push_back(vs);
    }
    for (int i = 0; i < n; i++)
    {
        vector<string> vs;
        if (!v[i])
        {
            vs.push_back(strs[i]);
        }
        if (vs.size())
        {
            vvs.push_back(vs);
        }
    }
    return vvs;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> vvs;
    int n = strs.size();
    vvs.reserve(n);

    vector<int> v(n, 0);//标记

    for (int i = 0; i < n; i++)
    {
        vector<string> vs;
        for (int j = i; j < n; j++)
        {
            if (isAnagram(strs[i], strs[j]) && !v[j])
            {
                v[j] = 1;
                vs.push_back(strs[j]);
            }
        }
        if (vs.size())
        {
            vvs.push_back(vs);
        }
        if (!vs.size() && !v[i])
        {
            vs.push_back(strs[i]);
            vvs.push_back(vs);
        }
    }
    return vvs;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);//
    }
    vector<vector<string>> ans;
    //不初始化，size和capability都为0
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{

	return 0;
}