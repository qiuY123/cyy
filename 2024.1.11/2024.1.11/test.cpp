#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

void deleteNode(ListNode* node) {
    ListNode* tmp = node;
    int size = 0;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    int mid = size / 2;
    ListNode* prev = node;
    ListNode* cur = node;
    while (mid--)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    delete cur;
}

ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* smallHead = small;
    ListNode* large = new ListNode(0);
    ListNode* largeHead = large;
    while (head) 
    {
        if (head->val < x) 
        {
            small->next = head;
            small = small->next;
        }
        else 
        {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = nullptr;
    small->next = largeHead->next;
    return smallHead->next;
}

int main()
{
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(5);
    node1->next = node2;
    ListNode* node3 = new ListNode(1);
    node2->next = node3;
    ListNode* node4 = new ListNode(9);
    node3->next = node4;
    deleteNode(node1);
	return 0;
}