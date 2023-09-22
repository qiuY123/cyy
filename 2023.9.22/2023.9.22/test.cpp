#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board) 
{
    int m = board.size();//��
    int n = board[0].size();//��

    vector<vector<int>> vv;
    vv.resize(m, vector<int>(n, -1));

    int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
    int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 1)//ϸ����Χ�Ļ�ϸ������
                {
                    count++;
                }
            }
            if (board[i][j] == 1 && (count < 2 || count>3))//��ϸ����Χ�˸�λ�õĻ�ϸ�������������򳬹�������ϸ�������λ�û�ϸ������
            {
                vv[i][j] = 0;
            }
            else if (board[i][j] == 1 && (count == 2 || count == 3))//��ϸ����Χ�˸�λ�õĻ�ϸ��������������ϸ�������λ�û�ϸ������
            {
                vv[i][j] = 1;
            }

            if (board[i][j] == 0 && count == 3)//��ϸ����Χ������������ϸ�������λ����ϸ������
            {
                vv[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vv[i][j] == 1)
            {
                board[i][j] = 1;
            }
            else if (vv[i][j] == 0)
            {
                board[i][j] = 0;
            }
        }
    }
}

bool canConstruct(string ransomNote, string magazine)
{
    int m = magazine.size();
    int n = ransomNote.size();

    int hash1[26] = { 0 }, hash2[26] = { 0 };

    for (int i = 0; i < m; i++)
    {
        hash1[magazine[i] - 'a']++;
    }

    for (int j = 0; j < n; j++)
    {
        hash2[ransomNote[j] - 'a']++;
    }

    for (int j = 0; j < n; j++)
    {
        if (hash2[ransomNote[j] - 'a'] > hash1[ransomNote[j] - 'a'])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> vv = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    gameOfLife(vv);
	return 0;
}