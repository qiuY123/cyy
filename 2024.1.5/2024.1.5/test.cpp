#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

vector<int> countBits(int n) {
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
    {
        int count = 0;
        int tmp = i;
        while (tmp)
        {
            if (tmp & 1)
            {
                count++;
            }
            tmp = tmp >> 1;
        }
        v[i] = count;
    }
    return v;
}

vector<vector<int>> ans;
vector<int> path;
void dfs(int target, int k, int sum, int start)
{
    if (path.size() == k)
    {
        if (sum == target)
        {
            ans.push_back(path);
        }
        return;
    }
    for (int i = start; i <= 9; i++)
    {
        sum += i;
        path.push_back(i);
        dfs(target, k, sum, i + 1);
        sum -= i;
        path.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    dfs(n, k, 0, 1);
    return ans;
}

int main()
{
	
	return 0;
}