#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minFlips(int a, int b, int c) {
    int count = 0;
    for (int i = 0; i < 31; ++i) {
        int bit_a = (a >> i) & 1;
        int bit_b = (b >> i) & 1;
        int bit_c = (c >> i) & 1;
        if (bit_c == 0) //双零为零，如果bit_a==1和bit_b==1都需要翻转.....
        {
            count += bit_a + bit_b;
        }
        else //有1为1，只要bit_a和bit_b有一个1就行
        {
            if (bit_a == 0 && bit_b == 0)
            {
                count++;
            }
        }
    }
    return count;
}

vector<vector<string>> suggestedProducts(vector<string>& ps, string w) {
    sort(ps.begin(), ps.end());
    int n = ps.size();
    vector<vector<string>> ans;
    for (int i = 0; i < w.length(); i++) {
        string cur = w.substr(0, i + 1);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (ps[mid].compare(cur) >= 0) r = mid;
            else l = mid + 1;
        }
        vector<string> list;
        if (ps[r].compare(cur) >= 0) {
            for (int j = r; j <= min(n - 1, r + 2); j++) {
                if (ps[j].length() < cur.length()) break;
                if (ps[j].substr(0, i + 1) != cur) break;
                list.push_back(ps[j]);
            }
        }
        ans.push_back(list);
    }
    return ans;

}

int main()
{

	return 0;
}