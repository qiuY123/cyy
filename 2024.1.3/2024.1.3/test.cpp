#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet()
        :index(1)
    {
        vb.resize(1001);
    }

    int popSmallest() {
        int ans = -1;
        if (!pq.empty())
        {
            ans = pq.top();
            pq.pop();
            vb[ans] = false;
        }
        else
        {
            ans = index++;
        }
        return ans;
    }

    void addBack(int num) {
        if (num >= index || vb[num])
        {
            return;
        }

        if (num == index - 1)
        {
            index--;
        }
        else
        {
            pq.push(num);
            vb[num] = true;
        }

    }
private:
    vector<bool> vb;
    priority_queue<int, vector<int>, greater<int>> pq;
    int index;
};

int guessNumber(int n) {
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (guess(mid) == 1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }

    }
    return l;
}

int main()
{
	return 0;
}