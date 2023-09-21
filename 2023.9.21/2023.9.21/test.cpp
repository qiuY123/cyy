#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < (n + 1) / 2; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tmp;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();//ÐÐ
    int n = matrix[0].size();//ÁÐ

    vector<vector<int>> vv;
    vv.resize(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int a = 0; a < m; a++)
                {
                    vv[a][j] = 1;
                }
                for (int b = 0; b < n; b++)
                {
                    vv[i][b] = 1;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vv[i][j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = { {0,1,2,0 }, {3, 4, 5, 2},{1, 3, 1, 5} };
    setZeroes(v);

	return 0;
}