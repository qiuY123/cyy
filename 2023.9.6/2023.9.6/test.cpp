#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    // int ret=0;
    // for(int i=0;i<prices.size();i++)
    // {
    //     for(int j=i+1;j<prices.size();j++)
    //     {
    //         if(prices[j]>prices[i])
    //             ret=max(ret,prices[j]-prices[i]);
    //     }
    // }
    int minprice = INT_MAX, maxprofit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minprice = min(prices[i], minprice);
        maxprofit = max(maxprofit, prices[i] - minprice);
    }
    return maxprofit;
}

int maxProfit(vector<int>& prices) {
    int buy = INT_MAX, sell = 0;
    long long max = 0;
    if (prices[0] < prices[1])
    {
        buy = prices[0];
    }
    for (int i = 1; i < prices.size() - 1; i++)
    {
        if (prices[i] < prices[i + 1])//不断迭代极大值卖出
        {
            sell = prices[i + 1];
        }
        if (prices[i] >= prices[i - 1] && prices[i] > prices[i + 1])//在区间极大值卖出-买入
        {
            max += sell - buy;
        }
        if (prices[i] <= prices[i - 1] && prices[i] < prices[i + 1])//区间内极小值买入
        {
            buy = prices[i];
        }
    }
    if (prices[prices.size() - 1] > prices[prices.size() - 2])
    {
        max += sell - buy;
    }
    return max;
}

int maxProfit(vector<int>& prices) {
    int sum = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[i - 1] > 0)
        {
            sum += prices[i] - prices[i - 1];
        }
    }
    return sum;
}

int main()
{


	return 0;
}