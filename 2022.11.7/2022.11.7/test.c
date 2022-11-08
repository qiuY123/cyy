#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            struct ListNode* meet = slow;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    while (cur)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = cur->val;

        newNode->next = cur->next;
        cur->next = newNode;

        cur = newNode->next;
    }
    cur = head;
    while (cur)
    {
        struct Node* newNode = cur->next;
        if (cur->random == NULL)
        {
            newNode->random = NULL;
        }
        else
        {
            newNode->random = cur->random->next;
        }
        cur = newNode->next;
    }
    struct Node* newhead = NULL;
    struct Node* newtail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        if (newtail == NULL)
        {
            newhead = newtail = copy;
        }
        else
        {
            newtail->next = copy;
            newtail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return newhead;
}