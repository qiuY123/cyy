#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.size(); i++)
    {
        int m = i, n = 0;
        while (1)
        {
            if (n >= needle.size())
            {
                return i;
            }
            if (haystack[m] == needle[n])
            {
                m++;
                n++;
            }
            else
            {
                break;
            }
        }
    }
    return -1;
}

bool isPalindrome(string s) {
    int n = s.size();
    if (n == 1)
    {
        return true;
    }
    string str;
    str.reserve(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            str += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            str += s[i] + 32;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            str += s[i] - 48;
        }
    }
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    isPalindrome(s);
	return 0;
}