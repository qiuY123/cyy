#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

void preorder(struct TreeNode* root, int* ret, int* retSize)
{
    if (root == NULL)
        return;
    ret[(*retSize)++] = root->val;
    preorder(root->left, ret, retSize);
    preorder(root->right, ret, retSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, ret, returnSize);
    return ret;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

bool isSymmetricTree(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    if (left == NULL || right == NULL || left->val != right->val)
    {
        return false;
    }
    return isSymmetricTree(left->left, right->right) && isSymmetricTree(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    return isSymmetricTree(root->left, root->right);
}

bool Subtree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if ((root1 == NULL || root2 == NULL) || root1->val != root2->val)
    {
        return false;
    }
    return Subtree(root1->left, root2->left) && Subtree(root1->right, root2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }
    return Subtree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
