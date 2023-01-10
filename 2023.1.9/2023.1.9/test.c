#define _CRT_SECURE_NO_WARNINGS 1 

int maxDepth(char* s) 
{
    int m = 0, n = 0;
    while (*s != '\0') 
    {
        switch (*s) 
        {
            case '(':
                m++; 
                break;
            case ')':
                m--; 
                break;
            default:
                break;
        }
        if (n < m) 
        { 
            n = m; 
        }
        if (*s != '\0') 
        {
            s++;
        }
    }
    return n;
}

struct ListNode* creatre()
{
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int sum = 0;
    int tmp = 0;
    struct ListNode* p, * q;
    struct ListNode* l3 = creatre();
    l3->next = NULL;
    l3->val = 0;
    q = l3;
    p = creatre();
    while (l1 || l2 || tmp)
    {
        p = creatre();
        sum = tmp + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
        p->val = sum % 10;
        tmp = sum / 10;
        p->next = q->next;
        q->next = p;
        q = p;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return l3->next;
}