#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

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

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    int count = 0;
    struct ListNode* cur = pListHead;
    struct ListNode* temp = pListHead;
    struct ListNode* tail = pListHead;
    while (tail)
    {
        tail = tail->next;
    }
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    if (k > count)
    {
        return tail;
    }
    for (int i = 0; i < count - k; i++)
    {
        cur = cur->next;
    }
    return cur;
}

if (list1 == NULL)
{
    return list2;
}
if (list2 == NULL)
{
    return list1;
}
struct ListNode* head = NULL;
struct ListNode* tail = NULL;
while (list1 && list2)
{
    if (list1->val < list2->val)
    {
        if (head == NULL)
        {
            head = tail = list1;
        }
        else
        {
            tail->next = list1;
            tail = list1;
        }
        list1 = list1->next;
    }
    else
    {
        if (head == NULL)
        {
            head = tail = list2;
        }
        else
        {
            tail->next = list2;
            tail = list2;
        }
        list2 = list2->next;
    }

}
if (list1)
{
    tail->next = list1;
}
if (list2)
{
    tail->next = list2;
}
return head;