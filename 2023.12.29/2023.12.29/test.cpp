#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

int maxlen = 0;
void dfs(TreeNode* root, int dir, int len)
{
    if (!root)
    {
        return;
    }
    maxlen = max(maxlen, len);
    if (dir)
    {
        dfs(root->left, 0, len + 1);
        dfs(root->right, 1, 1);
    }
    else
    {
        dfs(root->left, 0, 1);
        dfs(root->right, 1, len + 1);
    }
}
int longestZigZag(TreeNode* root)
{
    dfs(root->left, 0, 1);
    dfs(root->right, 1, 1);
    return maxlen;
}

int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);
    int levelsize = 1;
    int sum = INT_MIN;
    int minlevel = 1;
    int level = 1;
    while (!que.empty())
    {
        int tmpsum = 0;
        while (levelsize--)
        {
            TreeNode* tmp = que.front();
            tmpsum += tmp->val;
            que.pop();
            if (tmp->left)
            {
                que.push(tmp->left);
            }
            if (tmp->right)
            {
                que.push(tmp->right);
            }
        }
        levelsize = que.size();
        if (sum < tmpsum)
        {
            sum = tmpsum;
            minlevel = level;
        }
        level++;
    }
    return minlevel;
}

int main()
{

	return 0;
}