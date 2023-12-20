#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    if (n <= 1) return n; // ������鳤��С�ڵ���1��ֱ�ӷ����䳤��

    int write = 0; // д���λ��ָ��
    int read = 0;  // ��ȡ��λ��ָ��

    while (read < n) { // ����ȡָ��δ������ĩβʱ����������
        char currentChar = chars[read]; // ��¼��ǰ�ַ�
        int count = 0; // ����ͳ�Ƶ�ǰ�ַ��������ֵĴ���

        // ͳ�������ַ�������
        while (read < n && chars[read] == currentChar) {
            read++; // �ƶ���ȡָ��
            count++; // ���Ӽ�����
        }

        // ����ǰ�ַ�д��writeָ���λ��
        chars[write++] = currentChar;

        // �����ǰ�ַ���������������1���򽫸�����תΪ�ַ�������д������
        if (count > 1) {
            for (char c : std::to_string(count)) { // ���ڴ�����ÿ�������ַ�
                chars[write++] = c; // �������ַ�д������
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
        if (nums[i] + nums[j] == k) { //�ҵ����Ԫ�غ󵯳����������Լ���
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