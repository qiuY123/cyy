#define _CRT_SECURE_NO_WARNINGS 1 

class sum
{
public:
    sum()
    {
        _sum += _i;
        _i++;
    }
    static int GetSum()
    {
        return _sum;
    }
private:
    static int _i;
    static int _sum;
};

int sum::_i = 1;
int sum::_sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        sum a[n];
        return sum::GetSum();
    }
};

#include <iostream>
using namespace std;

int Is_LeapYear(int year)
{
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int GetMonthDay(int year, int month)
{
    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && Is_LeapYear(year))
    {
        ++arr[2];
    }
    return arr[month];
}

int GetReDay(int year, int month, int day)
{
    int x = GetMonthDay(year, month);
    return x - day;
}

int main()
{
    int n = 0;
    cin >> n;
    int year, month, day, num;
    for (int i = 0; i < n; i++)
    {
        cin >> year >> month >> day >> num;
        int remonth = GetReDay(year, month, day);
        if (num < remonth)
        {
            day += num;
        }
        else
        {
            num -= remonth;
            month++;
            if (month > 12)
            {
                year++;
                month = 1;
                day = 1;
            }
            while (num > 0)
            {
                if (num < GetMonthDay(year, month))
                {
                    day += num;
                    num = 0;
                }
                else
                {
                    month++;
                    if (month > 12)
                    {
                        year++;
                        month = 1;
                    }
                    num -= GetMonthDay(year, month);
                }
            }
        }

        printf("%04d-%02d-%02d\n", year, month, day);
    }

}

#include <iostream>
#include <cstdio>
using  namespace  std;
int daytab[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);//判断闰年
}
int Numberofyear(int year)
{
    if (IsLeapYear(year))
    {
        return  366;
    }
    else
    {
        return  365;
    }
}

int main()
{
    int m, year, month, day, number;
    cin >> m;
    while (m--)
    {
        while (cin >> year >> month >> day >> number)
        {
            //转化为天数
            int row = IsLeapYear(year);
            for (int i = 0; i < month; ++i) {
                number += daytab[row][i];
            }
            number += day;
            //确定年
            while (number > Numberofyear(year))
            {
                number -= Numberofyear(year);
                year++;
            }
            //确定月
            month = 0;
            row = IsLeapYear(year);
            while (number > daytab[row][month])
            {
                number -= daytab[row][month];
                month++;

            }
            day = number;
            printf("%04d-%02d-%02d", year, month, day);
        }
    }
}