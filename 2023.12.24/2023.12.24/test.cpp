#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool closeStrings(string word1, string word2) {
    // if(word1.size()!=word2.size())
    // {
    //     return false;
    // }
    // unordered_map<char,int> ump1,ump2;
    // for(int i=0;i<word1.size();i++)
    // {
    //     ump1[word1[i]]++;
    //     ump2[word2[i]]++;
    // }
    // vector<int> v1,v2;
    // for(int i=0;i<word1.size();i++)
    // {
    //     v1.push_back(ump1[word1[i]]);
    //     v2.push_back(ump2[word2[i]]);
    // }
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    // for(int i=0;i<word1.size();i++)
    // {
    //     if(v1[i]!=v2[i])
    //     {
    //         return false;
    //     }
    // }
    // return true;
    vector<int> count1(26), count2(26);
    for (char c : word1) {
        count1[c - 'a']++;
    }
    for (char c : word2) {
        count2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count1[i] > 0 && count2[i] == 0 || count1[i] == 0 && count2[i] > 0) {
            return false;
        }
    }
    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());
    return count1 == count2;

}

// bool equal(int row,int col,vector<vector<int>>& grid)
    // {
    //     int n=grid.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         if(grid[row][i]!=grid[i][col])
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // } 
    // int equalPairs(vector<vector<int>>& grid) {
    //     int ret=0;
    //     int n=grid.size();
    //     for(int row=0;row<n;row++)
    //     {
    //         for(int col=0;col<n;col++)
    //         {
    //             if(equal(row,col,grid))
    //             {
    //                 ret++;
    //             }
    //         }
    //     }
    //     return ret;
    // }
int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<vector<int>, int> cnt;
    for (auto row : grid) {
        cnt[row]++;
    }

    int res = 0;
    for (int j = 0; j < n; j++) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.emplace_back(grid[i][j]);
        }
        if (cnt.find(arr) != cnt.end()) {
            res += cnt[arr];
        }
    }
    return res;
}

int main()
{

	return 0;
}