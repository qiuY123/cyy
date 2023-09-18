#define _CRT_SECURE_NO_WARNINGS 1 

#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

string minWindow(string s, string t) {
    vector<vector<int>> vv;
    map<char, int> m1;
    int count = t.size();
    for (int i = 0; i < t.size(); i++)
    {
        m1[t[i]]++;
    }
    map<char, int> m2(m1);
    int n = s.size();
    int ret = INT_MAX;
    int left = 0, right = -1;
    int count1 = 0;
    for (; left < n; left++)
    {
        int tmp = 0;
        if (n - left < t.size())
        {
            break;
        }
        if (m2[s[left]])
        {

            m2[s[left]]--;//
            count1 = 1;
            right = left + 1;
            for (; right <= n; right++)
            {
                if (count1 == count)
                {
                    ret = min(ret, right - left);
                    vv.push_back({ left,right });
                    break;
                }
                if (right < n && m2[s[right]])//必须做判断，否则无法保证加的不是相同值（如s=“ccccca”，t=“ca”）会导致“cc”符合
                {
                    if (count1 == 1)
                    {
                        tmp = right;
                    }
                    m2[s[right]]--;//
                    count1++;
                }
            }
        }
        m2 = m1;
    }
    if (vv.size() == 0)
    {
        return "";
    }
    int i = 0;
    while (i < vv.size())
    {
        if (ret == vv[i][1] - vv[i][0])
        {
            break;
        }
        i++;
    }
    if (ret == 0)
    {
        ret = 1;
    }
    return s.substr(vv[i][0], ret);
}

int main()
{
    string s = "ab";
    string t = "b";
    string tmp = minWindow(s, t);
    return 0;
}