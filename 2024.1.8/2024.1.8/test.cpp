#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

bool oneEditAway(string first, string second) {
    int lf = first.length(), ls = second.length();
    if (lf > ls)
        return oneEditAway(second, first);
    if (ls - lf > 1)
        return false;
    if (lf == ls) {
        int count = 0;
        for (int i = 0; i < lf; i++) {
            if (first[i] != second[i])
                count++;
        }
        return count <= 1;
    }
    int i = 0, ofs = 0;
    while (i < lf) {
        if (first[i] != second[i + ofs]) {
            if (++ofs > 1)
                return false;
        }
        else {
            i += 1;
        }
    }
    return true;
}

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

int main()
{

	return 0;
}