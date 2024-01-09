#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> rows(m);
    vector<bool> cols(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!matrix[i][j]) {
                // 标记第 i 行和第 j 列需要被清零
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 如果第 i 行 或 第 j 列被标记过，将当前元素清零
            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

bool isFlipedString(string s1, string s2) {
    if (s1.size() == s2.size())
    {
        if (s1 == s2)
        {
            return true;
        }
        string s = s1 + s1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s.substr(i, s1.size()) == s2)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

int main()
{

	return 0;
}