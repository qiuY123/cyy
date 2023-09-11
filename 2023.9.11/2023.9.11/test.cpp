#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<string>

using namespace std;

int romanToInt(string s) {
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            sum += 1;
            if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'))
            {
                sum -= 2;
            }
        }
        else if (s[i] == 'V')
        {
            sum += 5;
        }
        else if (s[i] == 'X')
        {
            sum += 10;
            if (i + 1 < n && (s[i + 1] == 'L' || s[i + 1] == 'C'))
            {
                sum -= 20;
            }
        }
        else if (s[i] == 'L')
        {
            sum += 50;
        }
        else if (s[i] == 'C')
        {
            sum += 100;
            if (i + 1 < n && (s[i + 1] == 'D' || s[i + 1] == 'M'))
            {
                sum -= 200;
            }
        }
        else if (s[i] == 'D')
        {
            sum += 500;
        }
        else
        {
            sum += 1000;
        }
    }
    return sum;
}

string intToRoman(int num) {
    string s;
    while (num)
    {
        if (num >= 1000)
        {
            if (num == 1000)
            {
                s += 'M';
                break;
            }
            s += 'M';
            num -= 1000;
        }
        if (num < 1000 && num >= 900)
        {
            if (num == 900)
            {
                s += "CM";
                break;
            }
            s += "CM";
            num -= 900;
        }
        if (num >= 500 && num < 900)
        {
            if (num == 500)
            {
                s += 'D';
                break;
            }
            s += "D";
            num -= 500;
        }
        if (num < 500 && num >= 400)
        {
            if (num == 400)
            {
                s += "CD";
                break;
            }
            s += "CD";
            num -= 400;
        }
        if (num < 400 && num >= 100)
        {
            if (num == 100)
            {
                s += 'C';
                break;
            }
            s += 'C';
            num -= 100;
        }
        if (num < 100 && num >= 90)
        {
            if (num == 90)
            {
                s += "XC";
                break;
            }
            s += "XC";
            num -= 90;
        }
        if (num < 90 && num >= 50)
        {
            if (num == 50)
            {
                s += 'L';
                break;
            }
            s += 'L';
            num -= 50;
        }
        if (num < 50 && num >= 40)
        {
            if (num == 40)
            {
                s += "XL";
                break;
            }
            s += "XL";
            num -= 40;
        }
        if (num < 40 && num >= 10)
        {
            if (num == 10)
            {
                s += 'X';
                break;
            }
            s += 'X';
            num -= 10;
        }
        if (num == 9)
        {
            s += "IX";
            num -= 9;
            break;
        }
        if (num >= 5 && num < 9)
        {
            if (num == 5)
            {
                s += 'V';
                break;
            }
            s += 'V';
            num -= 5;
        }
        if (num == 4)
        {
            s += "IV";
            num -= 4;
            break;
        }
        if (num < 4)
        {
            s += 'I';
            num--;
        }
    }
    return s;
}

int main()
{



	return 0;
}