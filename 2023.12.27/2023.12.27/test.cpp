#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* oddEvenList(ListNode* head) {
    ListNode* newnode1 = new ListNode();
    ListNode* nodetail1 = newnode1;
    ListNode* newnode2 = new ListNode();
    ListNode* nodetail2 = newnode2;
    ListNode* tmp = head;
    while (tmp)
    {
        if (tmp->val % 2 == 1)
        {
            nodetail1->next = tmp;
            nodetail1 = nodetail1->next;
        }
        else
        {
            nodetail2->next = tmp;
            nodetail2 = nodetail2->next;
        }
        tmp = tmp->next;
    }
    if (nodetail1->next)
    {
        newnode1->next = nullptr;
    }
    if (nodetail2->next)
    {
        newnode2->next = nullptr;
    }
    if (head->val % 2 == 1)
    {
        nodetail1->next = newnode2->next;
    }
    else
    {
        nodetail2->next = newnode1->next;
    }
    return head;
}

ListNode* oddEvenList(ListNode* head) {
    ListNode* newnode1 = new ListNode();
    ListNode* nodetail1 = newnode1;
    ListNode* newnode2 = new ListNode();
    ListNode* nodetail2 = newnode2;
    ListNode* tmp = head;
    int count = 1;
    while (tmp)
    {
        if (count % 2 == 1)
        {
            nodetail1->next = tmp;
            nodetail1 = nodetail1->next;
        }
        else
        {
            nodetail2->next = tmp;
            nodetail2 = nodetail2->next;
        }
        count++;
        tmp = tmp->next;
    }
    if (nodetail1->next)
    {
        nodetail1->next = nullptr;
    }
    if (nodetail2->next)
    {
        nodetail2->next = nullptr;
    }
    // if(head->val%2==1)
    // {
    //     nodetail1->next=newnode2->next;
    // }
    // else
    // {
    //     nodetail2->next=newnode1->next;
    // }
    nodetail1->next = newnode2->next;
    // while(newnode1)
    // {
    //     cout<<newnode1->val<<endl;
    //     newnode1=newnode1->next;
    // }
    // while(newnode2)
    // {
    //     cout<<newnode2->val<<endl;
    //     newnode2=newnode2->next;
    // }
    return head;
}

int pairSum(ListNode* head) {
    vector<int>a;
    while (head != nullptr) {
        a.push_back(head->val);
        head = head->next;
    }
    int result = INT_MIN, temp;
    int n = a.size();
    for (int i = 0; i <= (n / 2 - 1); i++) {
        temp = a[i] + a[n - 1 - i];
        result = max(temp, result);
    }
    return result;
}

int main()
{

	return 0;
}