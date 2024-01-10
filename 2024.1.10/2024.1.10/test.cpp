#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

ListNode* removeDuplicateNodes(ListNode* head) {
    unordered_map<int, int> ump;
    ListNode* cur = head;
    ListNode* prev;
    while (cur)
    {
        if (ump[cur->val] == 0)
        {
            ump[cur->val]++;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            ListNode* tmp = cur;
            cur = cur->next;
            prev->next = cur;
            delete tmp;
        }
    }
    return head;
}

int kthToLast(ListNode* head, int k) {
    vector<int> v;
    ListNode* tmp = head;
    while (tmp)
    {
        v.push_back(tmp->val);
        tmp = tmp->next;
    }
    return v[v.size() - k];
}

int main()
{

	return 0;
}