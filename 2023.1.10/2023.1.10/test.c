#define _CRT_SECURE_NO_WARNINGS 1 

int arr[1001] = { 0 };

void Preorder(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    arr[root->val] = 1;

    Preorder(root->left);
    Preorder(root->right);
}

int numColor(struct TreeNode* root)
{
    memset(arr, 0, sizeof(arr));
    Preorder(root);
    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (arr[i])
            count++;
    }
    return count;
}

char* makeGood(char* s) 
{
    int i = 0;
    for (int j = 1; j < strlen(s); j++) 
    {
        if (i == -1 || (s[i] != s[j] - 32 && s[i] != s[j] + 32)) 
        {
            s[++i] = s[j];
        }
        else 
        {
            i--;
        }
    }
    s[++i] = '\0';
    return s;
}

