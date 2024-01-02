#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int, int>> q;

    int dires[5] = { 1, 0, -1, 0, 1 };
    int rows = maze.size();
    int cols = maze[0].size();
    q.push({ entrance[0], entrance[1] });
    maze[entrance[0]][entrance[1]] = '+';
    int steps = 0;
    while (!q.empty())
    {
        ++steps;
        for (int i = q.size(); i > 0; --i)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; ++j)
            {
                int nx = x + dires[j];
                int ny = y + dires[j + 1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] != '+')
                {
                    if (nx == 0 || nx == rows - 1 || ny == 0 || ny == cols - 1)
                    {
                        // cout << nx << " " << ny << " reachs final" << endl;
                        return steps;
                    }
                    maze[nx][ny] = '+';
                    q.push({ nx, ny });
                }
            }
        }
    }

    return -1;
}

int orangesRotting(vector<vector<int>>& grid) {
    int min = 0, fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 1) fresh++;
            else if (grid[i][j] == 2) q.push({ i, j });
    }
    vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!q.empty()) {
        int n = q.size();
        bool rotten = false;
        for (int i = 0; i < n; i++) {
            auto x = q.front();
            q.pop();
            for (auto cur : dirs) {
                int i = x.first + cur.first;
                int j = x.second + cur.second;
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                    grid[i][j] = 2;
                    q.push({ i, j });
                    fresh--;
                    rotten = true;
                }
            }
        }
        if (rotten) min++;
    }
    return fresh ? -1 : min;
}

int main()
{

	return 0;
}