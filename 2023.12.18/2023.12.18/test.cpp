#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> vb(candies.size());
    int mx = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        mx = max(mx, candies[i]);
    }
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= mx)
        {
            vb[i] = true;
        }
        else
        {
            vb[i] = false;
        }
    }
    return vb;
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0)
        {
            if (n <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (n == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    int ini = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 1)
        {
            ini++;
        }
    }
    //cout<<ini<<endl;
    if (flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        flowerbed[0] = 1;
    }
    if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0)
    {
        flowerbed[flowerbed.size() - 1] = 1;
    }
    for (int i = 1; i < flowerbed.size() - 1; i++)
    {
        if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
        {
            flowerbed[i] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 1)
        {
            count++;
        }
    }
    //cout<<count<<endl;
    return (count - ini) >= n ? true : false;
}

int main()
{

	return 0;
}