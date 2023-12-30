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

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root)
    {
        return nullptr;
    }
    if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    else if (root->val < val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return root;
    }
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if (root == nullptr)    return nullptr;
    if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
    else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
    else    // 当前节点就是要删除的节点
    {
        if (!root->left)   return root->right; // 情况1，欲删除节点无左子
        if (!root->right)  return root->left;  // 情况2，欲删除节点无右子
        TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有 
        while (node->left)          // 寻找欲删除节点右子树的最左节点
            node = node->left;
        node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
        root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
    }
    return root;
}
// TreeNode* deleteNode(TreeNode* root, int key) {
//     if(root==nullptr)
//     {
//         return nullptr;
//     }

//     if(root->val==key)
//     {
//         if(root->left==nullptr&&root->right==nullptr)
//         {
//             delete root;
//             return nullptr;
//         }
//         else if(root->left&&root->right==nullptr)
//         {
//             TreeNode* next=root->left;
//             delete root;
//             return next;
//         }
//         else if(root->left==nullptr&&root->right)
//         {
//             TreeNode* next=root->right;
//             delete root;
//             return next;
//         }
//         else
//         {
//             TreeNode* next=root->right;
//             if(!next->left)
//             {
//                 next->left=root->left;
//                 delete root;
//                 return next; 
//             }
//             else
//             {
//                 TreeNode* prev=nullptr;
//                 while(next->left)
//                 {
//                     prev=next;
//                     next=next->left;
//                 }
//                 if(next->right)
//                 {
//                     prev->left=next->right;
//                     next->right=root->right;
//                     next->left=root->left;
//                     delete root;
//                     return next;
//                 }
//                 else
//                 {
//                     prev->left=nullptr;
//                     next->right=root->right;
//                     next->left=root->left;
//                     delete root;
//                     return next;
//                 }
//             }
//         }
//     }   
//     else
//     {
//         TreeNode* tmp=root;
//         TreeNode* prev=nullptr;
//         while(tmp)
//         {
//             if(tmp->val>key)
//             {
//                 prev=tmp;
//                 tmp=tmp->left;
//             }
//             else if(tmp->val<key)
//             {
//                 prev=tmp;
//                 tmp=tmp->right;
//             }
//             else
//             {
//                 if(tmp->left==nullptr&&tmp->right==nullptr)
//                 {
//                     delete tmp;
//                     //tmp=nullptr;
//                 }
//                 else if(tmp->left==nullptr&&tmp->right)
//                 {
//                     //TreeNode* next=tmp->right;
//                     if(prev->left==tmp)
//                     {
//                         prev->left=tmp->right;
//                     }
//                     else
//                     {
//                         prev->right=tmp->right;
//                     }
//                     delete tmp;
//                     //tmp=nullptr;
//                 }
//                 else if(tmp->left&&tmp->right==nullptr)
//                 {

//                     if(prev->left==tmp)
//                     {
//                         prev->left=tmp->left;
//                     }
//                     else
//                     {
//                         prev->right=tmp->left;
//                     }
//                     delete tmp;
//                 }
//                 else
//                 {
//                     TreeNode* next=tmp->right;
//                     if(!next->left)
//                     {
//                         if(prev->left==tmp)
//                         {
//                             prev->left=next;
//                         }
//                         else
//                         {
//                             prev->right=next;
//                         }
//                         next->left=tmp->left;
//                     }
//                     else
//                     {
//                         TreeNode* pre=nullptr;
//                         while(next->left)
//                         {
//                             pre=next;
//                             next=next->left;
//                         }
//                         if(next->right)
//                         {
//                             pre->left=next->right;
//                             next->right=tmp->right;
//                             next->left=tmp->left;
//                             delete tmp;
//                         }
//                         else
//                         {
//                             pre->left=nullptr;
//                             next->right=tmp->right;
//                             next->left=tmp->left;
//                             delete tmp;
//                         }
//                     }
//                 }
//                 break;
//             }
//         }
//     }

//     return root;
// }

int main()
{

	return 0;
}