#define _CRT_SECURE_NO_WARNINGS 1 

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            if (cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
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