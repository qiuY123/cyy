#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int count1 = 0;
    ListNode* tmp1 = headA;
    while (tmp1)
    {
        count1++;
        tmp1 = tmp1->next;
    }
    int count2 = 0;
    ListNode* tmp2 = headB;
    while (tmp2)
    {
        count2++;
        tmp2 = tmp2->next;
    }
    if (count2 > count1)
    {
        int size = count2 - count1;
        while (size--)
        {
            headB = headB->next;
        }
    }
    else
    {
        int size = count1 - count2;
        while (size--)
        {
            headA = headA->next;
        }
    }
    while (headA && headB)
    {
        if (headA == headB)
        {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

ListNode* reverseList(ListNode* node)
{
    ListNode* prev = node;
    ListNode* Next;
    ListNode* cur = node->next;
    while (cur)
    {
        if (prev == node)
        {
            prev->next = nullptr;
        }
        Next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = Next;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
    {
        return true;
    }
    int count = 0;
    ListNode* tmp = head;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    tmp = head;
    ListNode* pre = nullptr;
    if (count % 2)
    {
        int mid = count / 2 + 1;
        while (mid--)
        {
            pre = tmp;
            tmp = tmp->next;
        }
        if (pre)
        {
            pre->next = nullptr;
        }
        ListNode* newnode = reverseList(tmp);
        while (newnode && head)
        {
            if (newnode->val != head->val)
            {
                return false;
            }
            newnode = newnode->next;
            head = head->next;
        }
    }
    else
    {
        int mid = count / 2;
        while (mid--)
        {
            pre = tmp;
            tmp = tmp->next;
        }
        if (pre)
        {
            pre->next = nullptr;
        }
        ListNode* newnode = reverseList(tmp);
        while (newnode && head)
        {
            if (newnode->val != head->val)
            {
                return false;
            }
            newnode = newnode->next;
            head = head->next;
        }
    }
    return true;
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(2);
    node2->next = node3;
    ListNode* node4 = new ListNode(2);
    node3->next = node4;
    ListNode* node5 = new ListNode(1);
    node4->next = node5;
    isPalindrome(node1);
	return 0;
}