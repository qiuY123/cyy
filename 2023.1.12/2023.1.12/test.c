#define _CRT_SECURE_NO_WARNINGS 1 

#define N 100000

bool isEvenOddTree(struct TreeNode* root)
{
    struct TreeNode* queue[N];
    int front = 0;
    int rear = 0;
    int odd = 0;
    int prev;

    queue[rear++] = root;

    while (front != rear)
    {
        int cnt = rear - front;
        if (odd == 1)
            prev = INT_MAX;
        if (odd == 0)
            prev = INT_MIN;
        for (int i = 0; i < cnt; i++)
        {
            root = queue[front++];
            if ((odd == 1) && (root->val % 2 != 0 || prev <= root->val))
                return false;
            if ((odd == 0) && (root->val % 2 != 1 || prev >= root->val))
                return false;

            prev = root->val;

            if (root->left)
                queue[rear++] = root->left;
            if (root->right)
                queue[rear++] = root->right;
        }
        odd = (odd + 1) % 2;
    }
    return true;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int index = 0;
    int hash[1001] = { 0 };
    for (int i = 0; i < arr1Size; ++i)
    {
        hash[arr1[i]]++;
    }

    for (int i = 0; i < arr2Size; ++i)
    {
        while (hash[arr2[i]] > 0)
        {
            arr1[index++] = arr2[i];
            hash[arr2[i]]--;
        }
    }

    for (int i = 0; i < 1001; ++i)
    {
        while (hash[i] > 0)
        {
            arr1[index++] = i;
            hash[i]--;
        }
    }
    *returnSize = arr1Size;
    return arr1;
}
