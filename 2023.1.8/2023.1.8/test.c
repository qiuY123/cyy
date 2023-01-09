#define _CRT_SECURE_NO_WARNINGS 1 

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (head->next == NULL || head == NULL)
        return head;
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->next = head;
    struct ListNode* ans, * tmp, * cur = ret;
    for (int i = 0; i < m - 1; i++)
    {
        cur = cur->next;
    }
    tmp = cur;
    struct ListNode* p;
    cur = cur->next;
    p = cur;
    for (int i = 0; i < n - m + 1; i++)
    {
        ans = cur;
        cur = cur->next;
        ans->next = tmp->next;
        tmp->next = ans;
    }
    p->next = cur;
    return ret->next;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head)
{
    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur->next = head;
    cur->val = 0;
    struct ListNode* p = cur;
    int x = 0;
    while (p)
    {
        struct ListNode* q = p->next;
        while (q)
        {
            x -= q->val;
            if (x == 0)
            {
                p->next = q->next;
            }
            q = q->next;
        }
        p = p->next;
        x = 0;
    }
    return cur->next;
}

