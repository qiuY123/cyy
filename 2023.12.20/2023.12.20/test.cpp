#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    if (n <= 1) return n; // 如果数组长度小于等于1，直接返回其长度

    int write = 0; // 写入的位置指针
    int read = 0;  // 读取的位置指针

    while (read < n) { // 当读取指针未到数组末尾时，继续遍历
        char currentChar = chars[read]; // 记录当前字符
        int count = 0; // 用来统计当前字符连续出现的次数

        // 统计连续字符的数量
        while (read < n && chars[read] == currentChar) {
            read++; // 移动读取指针
            count++; // 增加计数器
        }

        // 将当前字符写入write指针的位置
        chars[write++] = currentChar;

        // 如果当前字符的连续数量大于1，则将该数量转为字符串，并写入数组
        if (count > 1) {
            for (char c : std::to_string(count)) { // 对于次数的每个数字字符
                chars[write++] = c; // 将数字字符写入数组
            }
        }
    }

    return write;

    // unordered_map<char,int> ump;
    // for(int i=0;i<chars.size();i++)
    // {
    //     ump[chars[i]]++;
    // }
    // int count=0,size=0;
    // for(int i=0;i<chars.size();i++)
    // {
    //     if(ump[chars[i]])
    //     {
    //         count++;
    //         int tmp=ump[chars[i]];
    //         if(tmp>1)
    //         {
    //             while(tmp)
    //             {
    //                 size++;
    //                 tmp/=10;
    //             }
    //         }
    //     }
    // }
    // return count+size;
}

int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int op = 0;
    while (i < j) {
        if (nums[i] + nums[j] == k) { //找到相等元素后弹出（用自增自减）
            op++;
            i++;
            j--;
        }
        else if (nums[i] + nums[j] > k) j--;
        else if (nums[i] + nums[j] < k) i++;
    }
    return op;
}

int main()
{

	return 0;
}