#define _CRT_SECURE_NO_WARNINGS 1 

#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> v;
    int len = s.size();
    int m = words.size();
    int n = words[0].size();
    unordered_map<string, int> um1, um2;
    for (int i = 0; i < m; i++)
    {
        um1[words[i]]++;
        um2[words[i]]++;
    }
    int count = 0;
    for (int i = 0; i <= len - n; i++)
    {
        string strtmp(s.begin() + i, s.begin() + i + n);
        if (um2[strtmp])
        {
            um2[strtmp]--;
            count = 1;
            int tmp = 0;
            for (int j = i + n; j <= len - n; j += n)
            {
                if (count == m)
                {
                    //tmp = i;
                    break;
                }
                string strtmp(s.begin() + j, s.begin() + j + n);
                if (um2[strtmp])
                {
                    um2[strtmp]--;
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count == m)
            {
                v.push_back(i);
            }
        }
        um2 = um1;
    }
    return v;
}

int main()
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = { "word","good","best","good" };
    findSubstring(s, words);
    return 0;
}