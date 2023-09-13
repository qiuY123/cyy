#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>

using namespace std;

string reverseWords(string s) {
    int n = s.size();
    if (s[0] == ' ')
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                //s.erase(s.begin()+i);
            }
            else
            {
                s.erase(s.begin(), s.begin() + i);
                break;
            }
        }
    }
    n = s.size();
    if (s[n - 1] == ' ')
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                s.erase(s.begin() + i);
            }
            else
            {
                break;
            }
        }
    }

    n = s.size();
    reverse(s.begin(), s.end());
    string str;
    str.reserve(n);
    for (int i = 0; i < n;)
    {
        if (s[i]!=' ')
        {
            str += s[i];
            i++;
        }
        else
        {
            str += ' ';
            while (1)
            {
                i++;
                if (s[i] != ' ')
                {
                    break;
                }
            }
        }
    }
    n = str.size();
    int left = 0, right = 0;
    for (right = 0; right < n; right++)
    {
        if (str[right] == ' ')
        {
            reverse(str.begin() + left, str.begin() + right);
        }
        if (right - 1 >= 0 && str[right - 1] == ' ' && str[right] != ' ')
        {
            left = right;
        }
    }
    reverse(str.begin() + left, str.begin() + n);

    return str;
}

string convert(string s, int numRows) {
    if (numRows == 1)
    {
        return s;
    }
    int length = s.size();
    int n = 2 * numRows - 2;
    string str;
    str.reserve(length);
    for (int i = 0; i < length; i += n)
    {
        str += s[i];
    }
    for (int i = 1; i < numRows - 1; i++)
    {
        for (int j = i, k = n - i; j < length || k < length; j += n, k += n)
        {
            if (j < length)
            {
                str += s[j];
            }
            if (k < length)
            {
                str += s[k];
            }
        }
    }
    for (int i = numRows - 1; i < length; i += n)
    {
        str += s[i];
    }
    return str;
}

int main()
{
    string s = "a good   example";
    reverseWords(s);
	return 0;
}
