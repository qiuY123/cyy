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
    if (key > root->val)    root->right = deleteNode(root->right, key);     // ȥ������ɾ��
    else if (key < root->val)    root->left = deleteNode(root->left, key);  // ȥ������ɾ��
    else    // ��ǰ�ڵ����Ҫɾ���Ľڵ�
    {
        if (!root->left)   return root->right; // ���1����ɾ���ڵ�������
        if (!root->right)  return root->left;  // ���2����ɾ���ڵ�������
        TreeNode* node = root->right;           // ���3����ɾ���ڵ������Ӷ��� 
        while (node->left)          // Ѱ����ɾ���ڵ�������������ڵ�
            node = node->left;
        node->left = root->left;    // ����ɾ���ڵ����������Ϊ��������������ڵ��������
        root = root->right;         // ��ɾ���ڵ�����Ӷ�����λ�ã��ڵ㱻ɾ��
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