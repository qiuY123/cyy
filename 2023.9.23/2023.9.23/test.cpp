#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

bool isIsomorphic(string s, string t) {
    int hash1[128] = { 0 };
    int hash2[128] = { 0 };

    int m = s.size();
    int n = t.size();

    if (m != n)
    {
        return false;
    }

    map<char, char> ma;
    for (int i = 0; i < m; i++)
    {
        ma[s[i]] = t[i];
        hash1[s[i]]++;
        hash2[t[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (ma[s[i]] != t[i])//ӳ�䲻ͬ����false
        {
            return false;
        }
        if (hash1[s[i]] != hash2[t[i]])//���಻ͬ����false
        {
            return false;
        }
    }

    return true;
}

bool wordPattern(string pattern, string s) {
    vector<string> vs;
    int l = 0, r = 0;
    for (; r < s.size(); r++)
    {
        if (s[r] == ' ')
        {
            string tmp(s.begin() + l, s.begin() + r);
            vs.push_back(tmp);
            l = r + 1;
        }
    }
    string tmp(s.begin() + l, s.end());
    vs.push_back(tmp);
    int m = pattern.size(), n = vs.size();
    if (m != n)
    {
        return false;
    }

    //����ӳ��
    map<char, string> ma;
    map<string, char> fma;
    for (int i = 0; i < n; i++)
    {
        ma[pattern[i]] = vs[i];
        fma[vs[i]] = pattern[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (ma[pattern[i]] != vs[i])
        {
            return false;
        }
        if (fma[vs[i]] != pattern[i])
        {
            return false;
        }
    }
    // map<char,string> ma;
    // map<string,int> mi;
    // map<char,int> ci;
    // for(int i=0;i<n;i++)
    // {
    //     ma[pattern[i]]=vs[i];
    //     mi[vs[i]]++;
    //     ci[pattern[i]]++;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     if(ma[pattern[i]]!=vs[i])//ӳ�䲻ͬ
    //     {
    //         return false;
    //     }
    //     if(mi[vs[i]]!=ci[pattern[i]])//���������ͬ
    //     {
    //         return false;
    //     }
    // }
    return true;
}

int main()
{
    string s1 = "boo";
    string s2 = "far";
    isIsomorphic(s1, s2);
	return 0;
}
