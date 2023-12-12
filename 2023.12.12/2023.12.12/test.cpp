#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> v(temperatures.size(), 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int tmp = st.top();
            st.pop();
            v[tmp] = i - tmp;
        }
        st.push(i);
    }
    return v;
}

int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    vector<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back() + 1;
            int right = i - 1;
            ans = max(ans, (right - left + 1) * heights[cur]);
        }
        st.push_back(i);
    }
    return ans;

}

int mian()
{

	return 0;
}