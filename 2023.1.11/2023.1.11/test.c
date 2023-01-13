#define _CRT_SECURE_NO_WARNINGS 1 

int dfs(struct TreeNode* root, int val) 
{
    if (root == NULL)
        return 0;
    val = (val << 1) | root->val;
    if (!root->left && !root->right)
        return val;
    return dfs(root->left, val) + dfs(root->right, val);
}

int sumRootToLeaf(struct TreeNode* root) 
{
    return dfs(root, 0);
}

int dfs(struct TreeNode* root, int* sum) 
{
    if (root == NULL)					   
        return 0;

    int left = dfs(root->left, sum);    
    int right = dfs(root->right, sum);   

    *sum += abs(left - right);	       

    return left + right+ root->val;
}

int findTilt(struct TreeNode* root) 
{
    int ret = 0;                        

    dfs(root, &ret);

    return ret;
}
