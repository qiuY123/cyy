#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        que.push(t);
        while (que.front() < t - 3000)
        {
            que.pop();
        }
        return que.size();
    }
private:
    queue<int> que;
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* deleteMiddle(ListNode* head) {
    int size = 0;
    ListNode* tmp = head;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    if (size == 1)
    {
        return nullptr;
    }
    int count = size / 2;
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (count--)
    {
        prev = cur;
        cur = cur->next;
    }
    ListNode* Next = cur->next;
    if (prev)
        prev->next = Next;
    delete cur;

    return head;
}

int main()
{

	return 0;
}