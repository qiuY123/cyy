#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

string reverseVowels(string s) {
    unordered_map<char, int> ump;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
        {
            ump[s[i]]++;
        }
    }
    int begin = 0, end = s.size() - 1;
    while (begin < end)
    {
        while (ump.count(s[begin]) == 0)
        {
            if (begin < end)
            {
                begin++;
            }
            else
            {
                break;
            }
        }

        while (ump.count(s[end]) == 0)
        {
            if (begin < end)
            {
                end--;
            }
            else
            {
                break;
            }
        }
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
    return s;
}

bool increasingTriplet(vector<int>& nums) {
    int one = INT_MAX, two = INT_MAX;
    for (int three : nums) {
        if (three > two) return true;
        else if (three <= one) one = three;
        else two = three;
        // if(three > one && three < two) two = three;
    }
    return false;

}

int main()
{

	return 0;
}
