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
                // ��ǵ� i �к͵� j ����Ҫ������
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // ����� i �� �� �� j �б���ǹ�������ǰԪ������
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