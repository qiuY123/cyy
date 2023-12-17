#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

string mergeAlternately(string word1, string word2) {
    string s;
    s.resize(word1.size() + word2.size());
    int m = 0, n = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (word1.size() < word2.size())
        {
            if (i % 2 == 0 && m < word1.size())
            {
                s[i] = word1[m++];
            }
            else if (i % 2 == 1 || n < word2.size())
            {
                s[i] = word2[n++];
            }
        }
        else
        {
            if (i % 2 == 1 && n < word2.size())
            {
                s[i] = word2[n++];
            }
            else if (i % 2 == 0 || m < word1.size())
            {
                s[i] = word1[m++];
            }
        }
    }
    return s;
}

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1)
    {
        return "";
    }
    return str1.substr(0, __gcd((int)str1.length(), (int)str2.length()));
}

int main()
{

	return 0;
}
