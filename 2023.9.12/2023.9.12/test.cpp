#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size();
    int i = n - 1;
    while (i >= 0)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            break;
        }
        i--;
    }
    int j = i;
    while (j >= 0)
    {
        if (s[j] == ' ')
        {
            break;
        }
        j--;
    }
    return i - j;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
    {
        return "";
    }
    string s = strs[0];
    int n = strs.size();
    for (int i = 1; i < n; i++)
    {
        s = two_string_compare(s, strs[i]);
        if (s.size() == 0)
        {
            break;
        }
    }
    return s;
}

string two_string_compare(const string& s1, const string& s2)
{
    int length = min(s1.size(), s2.size());
    int n = 0;
    while (n < length && s1[n] == s2[n])
    {
        n++;
    }
    return s1.substr(0, n);
}

int main()
{
    string s = "Hello World";
    lengthOfLastWord(s);
	return 0;
}