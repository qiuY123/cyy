#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int result = 1;
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= intervals[i - 1][1])
            result++;
        else
            intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
    }
    return intervals.size() - result;
}

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int ans = 1;
        while (!stk.empty() && stk.top().first <= price) {
            ans += stk.top().second;
            stk.pop();
        }
        stk.push({ price, ans });
        return ans;
    }

private:
    stack<pair<int, int>> stk;
};

int main()
{

	return 0;
}