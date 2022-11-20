#define _CRT_SECURE_NO_WARNINGS 1 

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    int lefthigh = maxDepth(root->left);
    int righthigh = maxDepth(root->right);
    return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}