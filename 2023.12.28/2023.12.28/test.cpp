#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

void tree(TreeNode* root, vector<int>& v)
{
    if (!root->left && !root->right)
    {
        v.push_back(root->val);
        return;
    }
    else
    {
        if (root->left)
        {
            tree(root->left, v);
        }
        if (root->right)
        {
            tree(root->right, v);
        }
    }

}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    tree(root1, v1);
    tree(root2, v2);
    return v1 == v2;
}

int goodNodes(TreeNode* root, int mx = INT_MIN) {
    if (!root)
    {
        return 0;
    }
    int left = goodNodes(root->left, max(mx, root->val));
    int right = goodNodes(root->right, max(mx, root->val));
    return left + right + (mx <= root->val);
}

int main()
{


	return 0;
}