#define _CRT_SECURE_NO_WARNINGS 1 

class Solution {
public:
    int Is_Legal(char c)
    {
        if (c >= '0' && c <= '9')
            return 1;
        if (c == '+' || c == '-')
            return 1;
        return 0;
    }
    int StrToInt(string str)
    {
        int flag = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (!Is_Legal(str[i]))
            {
                return 0;
            }
            if (str[i] != '+' && str[i] != '-')
            {
                flag = 10 * flag + (str[i] - '0');
            }

        }
        if (str[0] == '-')
            return -flag;
        return flag;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string s;
        int cur = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || cur)
        {
            if (i >= 0)
                cur += num1[i--] - '0';
            if (j >= 0)
                cur += num2[j--] - '0';

            s.push_back(cur % 10 + '0');
            cur = cur / 10;
        }
        reverse(s.begin(), s.end());
        return s;

    }
};

class Solution {
public:
    int firstUniqChar(string s)
    {
        int a[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (a[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

