#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

string removeStars(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }
    string str;
    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    // stack<int> st1,st2;
    // if(asteroids[0]>0)
    // {
    //     st1.push(asteroids[0]);
    // }
    // else
    // {
    //     st2.push(asteroids[0]);
    // }
    // for(int i=1;i<asteroids.size();i++)
    // {
    //     if(st1.empty()||st2.empty())
    //     {
    //         if(asteroids[i]>0)
    //         {
    //             st1.push(asteroids[i]);
    //         }
    //         else
    //         {
    //             st2.push(asteroids[i]);
    //         }
    //     }
    //     while(!st1.empty()&&!st2.empty())
    //     {
    //         if(st1.top()+st2.top()>0)
    //         {
    //             st2.pop();
    //         }
    //         else if(st1.top()+st2.top()<0)
    //         {
    //             st1.pop();
    //         }
    //         else
    //         {
    //             st1.pop();
    //             st2.pop();
    //         }
    //     }
    // }
    // vector<int> v;
    // while(!st1.empty())
    // {
    //     v.push_back(st1.top());
    //     st1.pop();
    // }
    // while(!st2.empty())
    // {
    //     v.push_back(st2.top());
    //     st2.pop();
    // }
    // reverse(v.begin(),v.end());
    // return v;

    vector<int> st;
    for (auto aster : asteroids) {
        bool alive = true;
        while (alive && aster < 0 && !st.empty() && st.back() > 0) {
            alive = st.back() < -aster; // aster ÊÇ·ñ´æÔÚ
            if (st.back() <= -aster) {  // Õ»¶¥ÐÐÐÇ±¬Õ¨
                st.pop_back();
            }
        }
        if (alive) {
            st.push_back(aster);
        }
    }
    return st;

}

int main()
{

	return 0;
}