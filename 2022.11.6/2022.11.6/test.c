#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* smallhead;
        struct ListNode* smalltail;
        struct ListNode* bighead;
        struct ListNode* bigtail;
        smallhead = smalltail = (struct ListNode*)malloc(sizeof(struct ListNode));
        bighead = bigtail = (struct ListNode*)malloc(sizeof(struct ListNode));
        smalltail->next = bigtail->next = NULL;
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                smalltail->next = cur;
                smalltail = cur;

            }
            else
            {
                bigtail->next = cur;
                bigtail = cur;
            }
            cur = cur->next;
        }
        smalltail->next = bighead->next;
        bigtail->next = NULL;
        pHead = smallhead->next;
        free(smallhead);
        free(bighead);
        return pHead;
    }
};

struct ListNode* middleNode(struct ListNode* head) {
    int count = 0;
    struct ListNode* cur = head;
    struct ListNode* temp = head;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    int mid = count / 2;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    return temp;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* newnode = NULL;
    while (cur != NULL)
    {
        struct ListNode* next = cur->next;
        cur->next = newnode;
        newnode = cur;
        cur = next;
    }
    return newnode;
}

class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* mid = middleNode(A);
        struct ListNode* rhead = reverseList(mid);
        struct ListNode* e1 = A;
        struct ListNode* e2 = rhead;
        while (e1 && e2)
        {
            if (e1->val == e2->val)
            {
                e1 = e1->next;
                e2 = e2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* e1 = headA;
    struct ListNode* e2 = headB;
    int count1 = 0;
    int count2 = 0;
    while (e1)
    {
        count1++;
        e1 = e1->next;
    }
    while (e2)
    {
        count2++;
        e2 = e2->next;
    }
    if (count1 > count2)
    {
        int temp = count1 - count2;
        while (temp--)
        {
            headA = headA->next;
        }
    }
    else if (count2 > count1)
    {
        int temp = count2 - count1;
        while (temp--)
        {
            headB = headB->next;
        }
    }
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}