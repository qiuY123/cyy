#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool row[9][10];
bool col[9][10];
bool grid[3][3][10];

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0';
                if (row[i][num] || col[j][num] || grid[i / 3][j / 3][num])
                {
                    return false;
                }
                row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
            }
        }
    }
    return true;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size() - 1, n = matrix[0].size() - 1;
    vector<int> v;
    int s = 0;
    int l = 0;
    while (1)
    {
        for (int i = l; i <= n; i++)
        {
            v.push_back(matrix[s][i]);
        }
        if (++s > m)
        {
            break;
        }
        for (int i = s; i <= m; i++)
        {
            v.push_back(matrix[i][n]);
        }
        if (--n < l)
        {
            break;
        }
        for (int i = n; i >= l; i--)
        {
            v.push_back(matrix[m][i]);
        }
        if (--m < s)
        {
            break;
        }
        for (int i = m; i >= s; i--)
        {
            v.push_back(matrix[i][l]);
        }
        if (++l > n)
        {
            break;
        }
    }
    return v;
}

int main()
{


    return 0;
}